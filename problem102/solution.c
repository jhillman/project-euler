/* Problem 102 = 228 */

#include <stdio.h>

struct vector {
    int x;
    int y;
    int magnitude;
};

struct vector cross_product(struct vector one, struct vector two) {
    struct vector product;
    product.x = one.y * two.magnitude - one.magnitude * two.y;
    product.y = one.magnitude * two.x - one.x * two.magnitude;
    product.magnitude = one.x * two.y - one.y * two.x;

    return product;
}

int triangle_contains_point(int aX, int aY, int bX, int bY, int cX, int cY, int dX, int dY) {
    struct vector ab;
    struct vector bc;
    struct vector ca;
    struct vector da;
    struct vector db;
    struct vector dc;
    struct vector ab_x_ad;
    struct vector bc_x_bd;
    struct vector ca_x_cd;
    int abZ;
    int bcZ;
    int caZ;
    ab.x = aX - bX;
    ab.y = aY - bY;
    ab.magnitude = 0;
    bc.x = bX - cX;
    bc.y = bY - cY;
    bc.magnitude = 0;
    ca.x = cX - aX;
    ca.y = cY - aY;
    ca.magnitude = 0;
    da.x = dX - aX;
    da.y = dY - aY;
    da.magnitude = 0;
    db.x = dX - bX;
    db.y = dY - bY;
    db.magnitude = 0;
    dc.x = dX - cX;
    dc.y = dY - cY;
    dc.magnitude = 0;
    ab_x_ad = cross_product(ab, da);
    bc_x_bd = cross_product(bc, db);
    ca_x_cd = cross_product(ca, dc);
    abZ = ab_x_ad.magnitude >= 0;
    bcZ = bc_x_bd.magnitude >= 0;
    caZ = ca_x_cd.magnitude >= 0;
    return (abZ == bcZ && bcZ == caZ);
}

int main() {
    FILE *triangleFile;
    int i;
    int fscanfResult;
    int aX;
    int aY;
    int bX;
    int bY;
    int cX;
    int cY;
    int answer = 0;
    triangleFile = fopen("triangles.txt", "r");

    if (triangleFile) {
        for (i = 0; i < 1000; i++) {
            fscanfResult = fscanf(triangleFile, "%d,%d,%d,%d,%d,%d ",
                                  &aX, &aY, &bX, &bY, &cX, &cY);
            answer += triangle_contains_point(
                          aX, aY, bX, bY, cX, cY, 0, 0);
        }

        fclose(triangleFile);
    }

    printf("%d", answer);

    return 0;
}
