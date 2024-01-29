#include "../../include/Action.h" 


BaseAction::BaseAction() {};

ActionStatus BaseAction::getStatus() const {
    return status;
};

void BaseAction::complete() {
    status = ActionStatus::COMPLETED;
};

void BaseAction::error(string errorMsg) {
    status = ActionStatus::ERROR;
    errorMsg = errorMsg;
};

string BaseAction::getErrorMsg() const {
    return errorMsg;
};

// ActionStatus BaseAction::setStatus(ActionStatus newstatus)
// {
//     this->status = newstatus;
// };