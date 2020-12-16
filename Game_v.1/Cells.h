#ifndef GAME_V_1_CELLS_H
#define GAME_V_1_CELLS_H
enum class CellsStatus{
    EMPTY,
    CROSS,
    ZERO
};

class Cells {
private:
    CellsStatus status;
public:
    Cells();

    void ChangeCellsStatus(CellsStatus newStatus);

    CellsStatus GetCellsStatus();

};
#endif //GAME_V_1_CELLS_H
