#ifndef BEZIERCURVE 
#define BEZIERCURVE 

#include "Vector3.h"
#include "DDLinkedList.h"

// three control points bezier curve
void beziercurve(Vector3 v0, Vector3 v1, Vector3 v2, DDLinkedList<Vector3>* ddl, int level) {
    if(level > 0) {
        Vector3 m0 = (v0 + v1)/2;
        Vector3 m1 = (v1 + v2)/2;
        Vector3 m = (m0 + m1)/2;
        beziercurve(v0, m0, m, ddl, level-1);
        ddl->append(m);
        m.print();
        beziercurve(m, m1, v2, ddl, level-1);
    }
}

// four control points bezier curve
void beziercurve4(Vector3 v0, Vector3 v1, Vector3 v2, Vector3 v3, DDLinkedList<Vector3>* ddl, int level) {
    if(level > 0) {
        Vector3 m01 = (v0 + v1)/2;
        Vector3 m12 = (v1 + v2)/2;
        Vector3 n12 = (m01 + m12)/2;
        Vector3 m23 = (v2 + v3)/2;
        Vector3 n23 = (m12 + m23)/2;
        beziercurve(v0, m01, n12, ddl, level);
        beziercurve(n12, m12, n23, ddl, level);
        beziercurve(n23, m23, v3, ddl, level);
    }
}
#endif
