#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ClosedHash.h"

static int hash(const char *key, int size)
{
    int num = 0;
    for (int i = 0; i < strlen(key); i++)
        num += (unsigned char)key[i];

    return num % size;
}

static int rehash(int key, int size)
{
    return (key + 1) % size;
}

static void SetBucket(Bucket *n, const Member *x, Status stat)
{
    n->data = *x;
    n->stat = stat;
}

int Initialize(ClosedHash *h, int size)
{
    if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;
    for (int i = 0; i < size; i++)
        h->table[i].stat = Empty;
    return 1;
}

Bucket *Search(const ClosedHash *h, const Member *x)
{
    int key = hash(x->name, h->size);
    Bucket *p = &h->table[key];

    for (int i = 0; p->stat != Empty && i < h->size; i++) {
        if (p->stat == Occupied && strcmp(p->data.name, x->name) == 0)
            return p;
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return NULL;
}

int Add(ClosedHash *h, const Member *x)
{
    int key = hash(x->name, h->size);
    Bucket *p = &h->table[key];

    if (Search(h, x))
        return 1;

    for (int i = 0; i < h->size; i++) {
        if (p->stat == Empty || p->stat == Deleted) {
            SetBucket(p, x, Occupied);
            return 0;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return 2;
}

int Remove(ClosedHash *h, const Member *x)
{
    Bucket *p = Search(h, x);

    if (p == NULL)
        return 1;

    p->stat = Deleted;
    return 0;
}

void Dump(const ClosedHash *h)
{
    for (int i = 0; i < h->size; i++) {
        printf("%02d : ", i);
        switch (h->table[i].stat) {
            case Occupied : printf("%s (%d)\n",
                                    h->table[i].data.name, h->table[i].data.no);
                            break;
            case Empty :    printf("-- 未登録 --\n");  break;
            case Deleted :  printf("-- 削除ずみ --\n");  break;
        }
    }
}

void Clear(ClosedHash *h)
{
    for (int i = 0; i < h->size; i++)
        h->table[i].stat = Empty;
}

void Terminate(ClosedHash *h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
