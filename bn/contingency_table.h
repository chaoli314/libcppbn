//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_CONTINGENCY_TABLE_H
#define LIBCPPBN_CONTINGENCY_TABLE_H


class contingency_table {


public:

#ifdef REPORT_STATS
    static int count;
#endif


private:
};

#ifdef REPORT_STATS
int contingency_table::count = 0;
#endif

#endif //LIBCPPBN_CONTINGENCY_TABLE_H
