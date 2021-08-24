#include <Portfolio.h>

namespace ti {

bool operator==(const PortfolioInfo& lhs, const PortfolioInfo& rhs) {
    if (lhs.positions.size() != rhs.positions.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.positions.size(); ++i) {
        if (!(lhs.positions[i] == rhs.positions[i])) {
            return false;
        }
    }

    if (lhs.currencies.size() != rhs.currencies.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.currencies.size(); ++i) {
        if (!(lhs.currencies[i] == rhs.currencies[i])) {
            return false;
        }
    }

    return true;
}

}