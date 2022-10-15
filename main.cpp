#include <iostream>
#include <vector>
#include "set.h"
#include "menu.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Set" << endl;

    Menu menu;
    menu.Run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "set.h"

TEST_CASE("isEmpty, isIn","[Set]")
{
    SECTION("Empty to one element search")
    {
        Set M;
        CHECK( M.isEmpty() );

        int e=1;
        CHECK_FALSE( M.isIn(e) );
        M.insert(e);
        CHECK_FALSE( M.isEmpty() );
        CHECK( M.isIn(e) );

        M.remove(e);
        CHECK( M.isEmpty() );
        CHECK_FALSE( M.isIn(e));
    }
    SECTION("Multiple element set search")
    {
        Set M;
        CHECK( M.isEmpty() );

        int e1=1;int e2=2;int e3=3;
        CHECK_FALSE( M.isIn(e2) );
        M.insert(e1);
        M.insert(e2);
        M.insert(e3);
        CHECK_FALSE( M.isEmpty() );
        CHECK( M.isIn(e3) );

        M.remove(e3);
        CHECK_FALSE( M.isEmpty());
        M.remove(e2);
        M.remove(e1);
        CHECK(M.isEmpty() );
        CHECK_FALSE( M.isIn(e3));
    }
}

TEST_CASE("insert","[Set]")
{
    Set M;;
    int e1=-1; int e2=2; int e3=3; int e4=4; int e5=5;
    M.insert(e2);
    CHECK( 1 == M.count());
    vector<int> v= M.getSet();
    CHECK( v[0] == e2 );

    M.insert(e5);
    CHECK( 2 == M.count());
    v= M.getSet();
    CHECK( v[0] == e2 ); CHECK( v[1] == e5 );

    M.insert(e1);M.insert(e3);M.insert(e4);
    CHECK( 5 == M.count());
    v= M.getSet();
    CHECK( v[0]== e2 ); CHECK( v[1] == e5); CHECK( e1 == v[2]); CHECK( e3 == v[3]); CHECK( e4 == v[4]);
}

TEST_CASE("Search","[Set]")
{
    SECTION("empty set")
    {
        Set M; unsigned int index;
        CHECK_FALSE(M.getSearch(3,index));
    }

    int e1=1; int e2=-2; int e3=3; int e4=4;
    SECTION("one element set")
    {
        Set M; unsigned int ind;
        M.insert(e1);
        CHECK(M.getSearch(e1,ind));
        CHECK(0 == ind);
        M.remove(e1);
        CHECK( 0 == M.count());
    }

    SECTION("more elements in the set, first is searched")
    {
        Set M; unsigned int ind1;
        M.insert(e4); M.insert(e2); M.insert(e3);
        CHECK(M.getSearch(e4,ind1));
        CHECK(0 == ind1);
        M.remove(e4);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e3); CHECK(v[1]==e2);
    }

    SECTION("more elements in the set, last is searched")
    {
        Set M; unsigned int ind2;
        M.insert(e4); M.insert(e2); M.insert(e3);
        CHECK(M.getSearch(e3,ind2));
        CHECK(2 == ind2);
        M.remove(e3);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e4); CHECK(v[1]==e2);
    }

    SECTION("more elements in the set, middle is searched")
    {
        Set M;unsigned int ind3;
        M.insert(e4); M.insert(e2); M.insert(e3);
        CHECK(M.getSearch(e2,ind3));
        CHECK(1 == ind3);
        M.remove(e2);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e4); CHECK(v[1]==e3);
    }

    SECTION("more elements in the set, searched value does not exist")
    {
        Set M; unsigned int ind; unsigned int ind2;
        M.insert(e4); M.insert(e2); M.insert(e3);
        CHECK_FALSE(M.getSearch(e1,ind));
        CHECK(M.getSearch(e4,ind2));
    }
}

TEST_CASE("remove","[Set]")
{
    int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;
    SECTION("remove from empty set")
    {
        Set M;
        CHECK_THROWS(M.remove(e2));
    }

    SECTION("remove first")
    {
        Set M;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.remove(e2);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e1); CHECK(v[1]==e3);
    }
    SECTION("remove last")
    {
        Set M;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.remove(e1);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e2); CHECK(v[1]==e3);
    }
    SECTION("remove middle")
    {
        Set M;

        M.insert(e2);
        M.insert(e3);
        M.insert(e1);

        M.remove(e3);
        CHECK( 2 == M.count());
        vector<int> v=M.getSet();
        CHECK(v[0]==e2); CHECK(v[1]==e1);
    }
}

TEST_CASE("exceptions","[Set]")
{
        int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;
        Set M;

        CHECK_THROWS(M.remove(2));
        CHECK_THROWS(M.rand_elem());

        M.insert(e5); M.insert(e2); M.insert(e3);

        CHECK_THROWS(M.insert(e5));
        CHECK_THROWS(M.insert(e2));
        CHECK_THROWS(M.insert(e3));

        CHECK_THROWS(M.remove(6));
        CHECK_THROWS(M.remove(7));

}

TEST_CASE("random element","[Set]")
{
    int e1=1; int e2=2; int e3=3; int e4=4; int e5=5;

    SECTION("try to get a random element from the empty set"){
        Set M;
        CHECK_THROWS(M.rand_elem());
    }

    SECTION("get random element from the set that has 1 element without removing it from the set"){
        Set M;
        M.insert(e1);
        CHECK(1==M.rand_elem());
        CHECK( 1 == M.count());
        CHECK_FALSE(2==M.rand_elem());
    }
    SECTION("get random element from the set that has multiple elements without removing it from the set"){
        Set M;
        M.insert(e1);
        M.insert(e2);
        M.insert(e3);

        bool l=false;
        vector<int> v=M.getSet();

        for(int i=0;i<M.count() && !l;i++){
            l=(v[i]==M.rand_elem());
        }
        CHECK(l==true);
        CHECK( 3 == M.count());
        CHECK_FALSE(5==M.rand_elem());
    }
}
TEST_CASE("count_even","[Set]")
{
    int e1=1; int e2=-2; int e3=3; int e4=4; int e5=5;int e6=6;
    SECTION("get count of even numbers from the empty set"){
        Set M;
        CHECK( 0 == M.getEvens());
    }
    SECTION("get count of even numbers from the set that has 1 element"){
        Set M;
        M.insert(e1);
        CHECK( 1 == M.count());
        CHECK( 0 == M.getEvens());
        M.remove(e1);
        CHECK( 0 == M.count());
        CHECK( 0 == M.getEvens());
        M.insert(e2);
        CHECK( 1 == M.count());
        CHECK( 1 == M.getEvens());
    }
    SECTION("get count of even numbers from the set which all elements are odd"){
        Set M;
        M.insert(e1);M.insert(e3);M.insert(e5);
        CHECK( 3 == M.count());
        CHECK( 0 == M.getEvens());
    }
    SECTION("get count of even numbers from the set which all elements are even"){
        Set M;
        M.insert(e2);M.insert(e4);M.insert(e6);
        CHECK( 3 == M.count());
        CHECK( 3 == M.getEvens());
    }
    SECTION("get count of even numbers from the set which all elements are mixed whether even and odd"){
        Set M;
        M.insert(e2);
        CHECK( 1 == M.count());
        CHECK( 1 == M.getEvens());
        M.insert(e3);
        CHECK( 2 == M.count());
        CHECK( 1 == M.getEvens());
        M.insert(e4);
        CHECK( 3 == M.count());
        CHECK( 2 == M.getEvens());
        M.insert(e5);
        CHECK( 4 == M.count());
        CHECK( 2 == M.getEvens());
    }
}
TEST_CASE("setting the set empty","[Set]")
{
    Set M; int e2=2;int e1=-1;

    CHECK(M.isEmpty());
    M.insert(e1); M.insert(e2);
    CHECK_FALSE(M.isEmpty());
    CHECK(2==M.count());
    M.setEmpty();
    CHECK(M.isEmpty());
    CHECK(0==M.count());
}

#endif
