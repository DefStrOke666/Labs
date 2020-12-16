#include "Cells.h"

Cells::Cells() {
    status = CellsStatus::EMPTY;
}

void Cells::ChangeCellsStatus(CellsStatus newStatus) {
    status = newStatus;
}

CellsStatus Cells::GetCellsStatus() {
    return status;
}
