#ifndef BEZIERSURFACEBATCH 
#define BEZIERSURFACEBATCH 

#include "Vector3.h"
#include "DDLinkedList.h"

class BezierSurfaceBatch {
    static int const PSIZE = 4;
    Vector3 arr[PSIZE][PSIZE];
    Curve* cListu[PSIZE];
    Curve** cListv = NULL;
    Node<Vector3>** currArr;
    int nCurve = 0;

    public:
    BezierSurfaceBatch(GLfloat arrf[PSIZE][PSIZE][3]) {
        for(int i=0; i<PSIZE; i++) {
            for(int j=0; j<PSIZE; j++) {
                arr[i][j] = Vector3(arrf[i][j]);
            }
        }
    }
    void create() {
        Node<Vector3>* curr[PSIZE];
        for(int i=0; i<PSIZE; i++) {
            cListu[i] = new Curve(arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
            curr[i] = cListu[i]->ddl->head;
        }

        nCurve = cListu[0]->ddl->count();
        int k = 0;
        cListv = new Curve*[nCurve];
        while(k < nCurve) {
            cListv[k] = new Curve(curr[0]->data, curr[1]->data, curr[2]->data, curr[3]->data);
            for(int i=0; i<PSIZE; i++) {
                curr[i] = curr[i]->next;
            }
            k++;
        }
    }
    void draw() {
        // initial four control points in u direction
        for(int i=0; i<PSIZE; i++) {
            cListu[i]->setColor(RED);
            cListu[i]->draw();
        }
        // each four control points for each bezier curve in v direction
        for(int i=0; i<nCurve; i++) {
            cListv[i]->setColor(WHITE);
            cListv[i]->draw();
        }
        connectCurve();
    }
    // connect v direction for all bezier curves
    void connectCurve(){
        currArr = new Node<Vector3>*[nCurve];
        for(int i=0; i<nCurve; i++) {
            currArr[i] = cListv[i]->ddl->head;
        }

        int count = 0;
        while(count < cListv[0]->ddl->count()) {
            glBegin(GL_LINE_STRIP); //starts drawing of points
            for(int i=0; i<nCurve; i++) {
                glColor3f(1.0, 1.0, 1.0);
                glVertex3f(currArr[i]->data.v[0], currArr[i]->data.v[1], currArr[i]->data.v[2]);
                currArr[i] = currArr[i]->next;
            }
            count++;
            glEnd();
        }
    }
    ~BezierSurfaceBatch() {
        for(int i=0; i<PSIZE; i++) {
            delete cListu[i];
        }

        for(int i=0; i<nCurve; i++) {
            delete cListv[i];
        }
        if(cListv)
            delete cListv;
        cListv = NULL;
    }
};


#endif
