#include "mll.h"

int main() {
    MLL mll;
    mll.createListParent();

    // ===== PARENT =====
    Parent *G1 = mll.alokasiNodeParent("G001", "Action");
    Parent *G2 = mll.alokasiNodeParent("G002", "Comedy");
    Parent *G3 = mll.alokasiNodeParent("G003", "Horror");
    Parent *G4 = mll.alokasiNodeParent("G004", "Romance");

    mll.insertFirstParent(G4);
    mll.insertFirstParent(G3);
    mll.insertFirstParent(G2);
    mll.insertFirstParent(G1);

    // ===== CHILD =====
    mll.insertLastChild(G1, mll.alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    mll.insertLastChild(G2, mll.alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    mll.insertLastChild(G2, mll.alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    mll.insertLastChild(G3, mll.alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    mll.insertLastChild(G4, mll.alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    mll.insertLastChild(G4, mll.alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    // PRINT
    mll.printStrukturMLL();

    // SEARCH
    mll.searchFilmByRatingRange(8.0, 8.5);

    // DELETE AFTER G001 (hapus G002)
    mll.deleteAfterParent("G001");

    cout << "\n=== SETELAH DELETE G002 ===\n";
    mll.printStrukturMLL();

    return 0;
}
