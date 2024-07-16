
/*
ID: michael504
LANG: C++
TASK: lis1
*/
#include <bits/stdc++.h>

using namespace std;
#define MAXWID 38
#define MAXHT 100

typedef struct Point Point;
struct Point {
	int r, c;
};

int wid, ht;
char lis[MAXHT*2+1][MAXWID*2+1+2];	/* extra +2 for "\n\0" */
int dist[MAXHT*2+1][MAXWID*2+1];

Point
Pt(int r, int c)
{
    Point p;

    p.r = r;
    p.c = c;
    return p;
}

typedef struct Queue Queue;
struct Queue {
    Point p;
    int d;
};

Queue floodq[MAXHT*MAXWID];
int bq, eq;

void
checkq(int d, Point p, Point np)
{
    if(lis[(p.r+np.r)/2][(p.c+np.c)/2] == ' ' && lis[np.r][np.c] == ' ') {
	lis[np.r][np.c] = '*';
	floodq[eq].p = np;
	floodq[eq].d = d+1;
	eq++;
    }
}

void
ok(Point exitp, Point startp)
{
    if(lis[exitp.r][exitp.c] == ' ') {
	checkq(0, startp, startp);
	lis[exitp.r][exitp.c] = '#';
    }
}

int
main()
{
    FILE *fin, *fout;
    Point p;
    int i, r, c, m, d;

    fin = fopen("lis1.in", "r");
    fout = fopen("lis1.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d\n", &wid, &ht);
    wid = 2*wid+1;
    ht = 2*ht+1;

    for(i=0; i<ht; i++)
	fgets(lis[i], sizeof(lis[i]), fin);

    /* find exits */
    for(i=1; i<wid; i+=2) {
	ok(Pt(0, i), Pt(1, i));
	ok(Pt(ht-1, i), Pt(ht-2, i));
    }
    for(i=1; i<ht; i+=2) {
	ok(Pt(i, 0), Pt(i, 1));
	ok(Pt(i, wid-1), Pt(i, wid-2));
    }

    assert(eq == 1 || eq == 2);	

    for(bq = 0; bq < eq; bq++) {
	p = floodq[bq].p;
	d = floodq[bq].d;
	dist[p.r][p.c] = d;

	checkq(d, p, Pt(p.r-2, p.c));
	checkq(d, p, Pt(p.r+2, p.c));
	checkq(d, p, Pt(p.r, p.c-2));
	checkq(d, p, Pt(p.r, p.c+2));
    }

    m = 0;
    for(r=0; r<ht; r++)
    for(c=0; c<wid; c++)
	if(dist[r][c] > m)
	    m = dist[r][c];

    fprintf(fout, "%d\n", m);

    exit(0);
}
