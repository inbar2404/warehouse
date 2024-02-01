#include "../../include/Action.h" 


BaseAction::BaseAction() : errorMsg(""), status(ActionStatus::COMPLETED) {}

BaseAction::~BaseAction() = default;

ActionStatus BaseAction::getStatus() const {
    return status;
};

void BaseAction::complete() {
    status = ActionStatus::COMPLETED;
};

void BaseAction::error(string errorMsg) {
    status = ActionStatus::ERROR;
    this->errorMsg = errorMsg;
};

string BaseAction::getErrorMsg() const {
    return errorMsg;
};

ActionStatus BaseAction::setStatus(ActionStatus newstatus)
{
    status = newstatus;
    return newstatus;
};