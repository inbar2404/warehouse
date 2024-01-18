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
    // TODO: Find out if here I should add to the template the "ERROR:"
    return errorMsg;
};