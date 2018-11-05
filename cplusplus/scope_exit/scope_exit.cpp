#include <boost/scope_exit>

void world::add_person(person const& a_person) {
    bool commit = false;

    persons_.push_back(a_person);           // (1) direct action
    // Following block is executed when the enclosing scope exits.
    BOOST_SCOPE_EXIT(&commit, &persons_) {
        if(!commit) persons_.pop_back();    // (2) rollback action
    } BOOST_SCOPE_EXIT_END

    // ...                                  // (3) other operations

    commit = true;                          // (4) disable rollback actions
}