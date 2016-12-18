//
// Created by chao li on 9/11/16.
//

#include <vector>

#include "gtest/gtest.h"
#include "sorted_set.h"

class sorted_set_Fixture : public ::testing::Test {
public:
    virtual ~sorted_set_Fixture() {}

protected:
    sorted_set_Fixture() : x1(1), x2(2), x3(3), x4(4), x5(5) {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const sorted_set<int> x1;
    const sorted_set<int> x2;
    const sorted_set<int> x3;
    const sorted_set<int> x4;
    const sorted_set<int> x5;
};


TEST_F(sorted_set_Fixture, ConstructorsTest) {
    std::vector<size_t> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3); // duplicate
    v.push_back(3); // duplicate
    v.push_back(3); // duplicate
    sorted_set<size_t> w(v.cbegin(), v.cend()); // convert to v sorted vector, and then unique it.

    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(w.size(), 4);

    EXPECT_EQ(1, w.front());
    EXPECT_EQ(1, w[0]);
    EXPECT_EQ(2, w[1]);
    EXPECT_EQ(3, w[2]);
    EXPECT_EQ(4, w[3]);
    EXPECT_EQ(4, w.back());
}


TEST_F(sorted_set_Fixture, QueriesTest) {
    // check queries
    sorted_set<int> x = x2 | x1;
    sorted_set<int> y = x2 | x3;
    sorted_set<int> z = x4 | x3;

    EXPECT_TRUE(x.contains(1));
    EXPECT_TRUE(x.contains(2));
    EXPECT_TRUE(!x.contains(3));
    EXPECT_TRUE(!x.contains(4));
    EXPECT_TRUE(!y.contains(1));
    EXPECT_TRUE(y.contains(2));
    EXPECT_TRUE(y.contains(3));
    EXPECT_TRUE(!y.contains(4));
    EXPECT_TRUE(!z.contains(1));
    EXPECT_TRUE(!z.contains(2));
    EXPECT_TRUE(z.contains(3));
    EXPECT_TRUE(z.contains(4));

    EXPECT_TRUE(x.intersects(y));
    EXPECT_TRUE(!x.intersects(z));
    EXPECT_TRUE(y.intersects(x));
    EXPECT_TRUE(y.intersects(z));
    EXPECT_TRUE(!z.intersects(x));
    EXPECT_TRUE(z.intersects(y));

    EXPECT_TRUE(!x.disjoint(y));
    EXPECT_TRUE(x.disjoint(z));

    EXPECT_TRUE(!x.includes(y));
    EXPECT_TRUE(!x.includes(z));

}


TEST_F(sorted_set_Fixture, operations_check) {
    sorted_set<int> x; // empty set
    sorted_set<int> x12  = x2 | x1;
    sorted_set<int> x23  = x2 | x3;
    sorted_set<int> x13  = x3 | x1;
    sorted_set<int> x123 = x12 | x3;
    sorted_set<int> y;

    // check insert
    y = x   ; y.insert( 1 );   EXPECT_EQ( y, x1   );
    y = x   ; y.insert( 2 );   EXPECT_EQ( y, x2   );
    y = x   ; y.insert( 3 );   EXPECT_EQ( y, x3   );
    y = x1  ; y.insert( 1 );   EXPECT_EQ( y, x1   );
    y = x1  ; y.insert( 2 );   EXPECT_EQ( y, x12  );
    y = x1  ; y.insert( 3 );   EXPECT_EQ( y, x13  );
    y = x2  ; y.insert( 1 );   EXPECT_EQ( y, x12  );
    y = x2  ; y.insert( 2 );   EXPECT_EQ( y, x2   );
    y = x2  ; y.insert( 3 );   EXPECT_EQ( y, x23  );
    y = x3  ; y.insert( 1 );   EXPECT_EQ( y, x13  );
    y = x3  ; y.insert( 2 );   EXPECT_EQ( y, x23  );
    y = x3  ; y.insert( 3 );   EXPECT_EQ( y, x3   );
    y = x12 ; y.insert( 1 );   EXPECT_EQ( y, x12  );
    y = x12 ; y.insert( 2 );   EXPECT_EQ( y, x12  );
    y = x12 ; y.insert( 3 );   EXPECT_EQ( y, x123 );
    y = x23 ; y.insert( 1 );   EXPECT_EQ( y, x123 );
    y = x23 ; y.insert( 2 );   EXPECT_EQ( y, x23  );
    y = x23 ; y.insert( 3 );   EXPECT_EQ( y, x23  );
    y = x13 ; y.insert( 1 );   EXPECT_EQ( y, x13  );
    y = x13 ; y.insert( 2 );   EXPECT_EQ( y, x123 );
    y = x13 ; y.insert( 3 );   EXPECT_EQ( y, x13  );
    y = x123; y.insert( 1 );   EXPECT_EQ( y, x123 );
    y = x123; y.insert( 2 );   EXPECT_EQ( y, x123 );
    y = x123; y.insert( 3 );   EXPECT_EQ( y, x123 );

    // check erase
    y = x   ; y.erase( 1 );    EXPECT_EQ( y, x    );
    y = x   ; y.erase( 2 );    EXPECT_EQ( y, x    );
    y = x   ; y.erase( 3 );    EXPECT_EQ( y, x    );
    y = x1  ; y.erase( 1 );    EXPECT_EQ( y, x    );
    y = x1  ; y.erase( 2 );    EXPECT_EQ( y, x1   );
    y = x1  ; y.erase( 3 );    EXPECT_EQ( y, x1   );
    y = x2  ; y.erase( 1 );    EXPECT_EQ( y, x2   );
    y = x2  ; y.erase( 2 );    EXPECT_EQ( y, x    );
    y = x2  ; y.erase( 3 );    EXPECT_EQ( y, x2   );
    y = x3  ; y.erase( 1 );    EXPECT_EQ( y, x3   );
    y = x3  ; y.erase( 2 );    EXPECT_EQ( y, x3   );
    y = x3  ; y.erase( 3 );    EXPECT_EQ( y, x    );
    y = x12 ; y.erase( 1 );    EXPECT_EQ( y, x2   );
    y = x12 ; y.erase( 2 );    EXPECT_EQ( y, x1   );
    y = x12 ; y.erase( 3 );    EXPECT_EQ( y, x12  );
    y = x13 ; y.erase( 1 );    EXPECT_EQ( y, x3   );
    y = x13 ; y.erase( 2 );    EXPECT_EQ( y, x13  );
    y = x13 ; y.erase( 3 );    EXPECT_EQ( y, x1   );
    y = x23 ; y.erase( 1 );    EXPECT_EQ( y, x23  );
    y = x23 ; y.erase( 2 );    EXPECT_EQ( y, x3   );
    y = x23 ; y.erase( 3 );    EXPECT_EQ( y, x2   );
    y = x123; y.erase( 1 );    EXPECT_EQ( y, x23  );
    y = x123; y.erase( 2 );    EXPECT_EQ( y, x13  );
    y = x123; y.erase( 3 );    EXPECT_EQ( y, x12  );
}