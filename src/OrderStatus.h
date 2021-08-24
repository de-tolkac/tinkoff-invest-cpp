#pragma once

namespace ti {

enum class OrderStatus {
    New, PartiallyFill, Fill, Cancelled, Replaced, PendingCancel, Rejected, PendingReplace, PendingNew
};

}