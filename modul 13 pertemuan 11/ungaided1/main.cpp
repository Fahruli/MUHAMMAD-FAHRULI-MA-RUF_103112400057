#include "MultiLL.h"

int main(){
    ListParent L;
    initParent(L);

    AdrParent G1 = newParent("G001","Aves");
    AdrParent G2 = newParent("G002","Mamalia");
    AdrParent G3 = newParent("G003","Pisces");
    AdrParent G4 = newParent("G004","Amfibi");
    AdrParent G5 = newParent("G005","Reptil");

    addParentLast(L,G1);
    addParentLast(L,G2);
    addParentLast(L,G3);
    addParentLast(L,G4);
    addParentLast(L,G5);

    addChildLast(G1->anak, newChild("AV001","Cendrawasih","Hutan",1,0.3));
    addChildLast(G1->anak, newChild("AV002","Bebek","Air",1,2));

    addChildLast(G2->anak, newChild("M001","Harimau","Hutan",1,200));
    addChildLast(G2->anak, newChild("M003","Gorila","Hutan",0,160));
    addChildLast(G2->anak, newChild("M002","Kucing","Darat",1,4));

    addChildLast(G4->anak, newChild("AM001","Kodok","Sawah",0,0.2));

    tampilMLL(L);
    return 0;
}
