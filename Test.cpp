#include "doctest.h"
#include "Team2.hpp"
#include "Team.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <stdexcept>
using namespace std;

namespace ariel
{
    TEST_CASE("TEST 1: Team2 AddCharacters Test")
    {
        Team2 team;
        Cowboy cowboy("John", Point(0, 0));
        Ninja ninja("Ryu", Point(1, 1), 10);
        team.add(&cowboy);
        team.add(&ninja);
        REQUIRE(team.stillAlive() == 2);
    }

    TEST_CASE("TEST 2: Team2 AttackOtherTeam Test")
    {
        Team2 team1;
        Team2 team2;
        Cowboy cowboy1("John", Point(0, 0));
        Cowboy cowboy2("Tom", Point(1, 1));
        Ninja ninja1("Ryu", Point(2, 2), 10);
        Ninja ninja2("Ken", Point(3, 3), 12);
        team1.add(&cowboy1);
        team1.add(&ninja1);
        team2.add(&cowboy2);
        team2.add(&ninja2);
        team1.attack(&team2);
        REQUIRE(team1.stillAlive() == 2);
        REQUIRE(team2.stillAlive() == 1);
    }

    TEST_CASE("TEST 3: Character IsAlive Test")
    {
        Character character("John", Point(0, 0), 100);
        REQUIRE(character.isAlive());
    }

    TEST_CASE("TEST 4: Character Distance Test")
    {
        // Point location1(0, 0);
        // Point location2(3, 4);
        Character character1("John", Point(0, 0), 100);
        Character character2("Jane", Point(3, 4), 100);
        double expectedDistance = 5.0;
        double actualDistance = character1.distance(&character2);
        REQUIRE(actualDistance == doctest::Approx(expectedDistance));
    }

    TEST_CASE("TEST 5: Character Hit Test")
    {
        //Point location(0, 0);
        Character character("John", Point(0, 0), 10);
        character.hit(10);
        REQUIRE_FALSE(character.isAlive());
    }

    TEST_CASE("TEST 6: Character GetName Test")
    {
        //Point location(0, 0);
        Character character("John", Point(0, 0), 100);
        std::string expectedName = "John";
        std::string actualName = character.getName();
        REQUIRE(actualName == expectedName);
    }

    TEST_CASE("TEST 7: Character Print Test")
    {
        //Point location(0, 0);
        Character character("John", Point(0, 0), 100);
        std::string expectedPrint = "Name: John, Location: (0, 0), Hit Points: 100";
        std::string actualPrint = character.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 8: Cowboy Print Test")
    {
       // Point location(0, 0);
        Cowboy cowboy("John", Point(0, 0));
        cowboy.reload();
        std::string expectedPrint = "Name: John, Location: (0, 0), Hit Points: 110, Bullets: 6";
        std::string actualPrint = cowboy.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 9: Ninja Print Test")
    {
        //Point location(0, 0);
        Ninja ninja("Rain", Point(0, 0), 10);
        std::string expectedPrint = "Name: Ryu, Location: (0, 0), Speed: 10";
        std::string actualPrint = ninja.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 10: YoungNinja Print Test")
    {
       // Point location(0, 0);
        YoungNinja youngNinja("Yoshi", Point(0, 0));
        std::string expectedPrint = "Ninja: Yoshi";
        std::string actualPrint = youngNinja.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 11: TrainedNinja Print Test")
    {
        //Point location(0, 0);
        TrainedNinja trainedNinja("Hanzo", Point(0, 0));
        std::string expectedPrint = "Ninja: Hanzo";
        std::string actualPrint = trainedNinja.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 12: OldNinja Print Test")
    {
       // Point location(0, 0);
        OldNinja oldNinja("Sensei", Point(0, 0));
        std::string expectedPrint = "Ninja: Sensei";
        std::string actualPrint = oldNinja.print();
        REQUIRE(actualPrint == expectedPrint);
    }

    TEST_CASE("TEST 13: Distance Method")
    {
        Point p1(1, 1);
        Point p2(2, 3);
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(p1.distance(p1), 0);
    }

    TEST_CASE("TEST 14: Team2 AddCharacters Test With Exceptions")
    {
        Team2 team;
        Cowboy cowboy("John", Point(0, 0));
        Ninja ninja("Ryu", Point(1, 1), 10);
        CHECK_NOTHROW(team.add(&cowboy));
        CHECK_NOTHROW(team.add(&ninja));
        // Adding the same character twice should throw an exception
        CHECK_THROWS_AS(team.add(&cowboy), std::runtime_error);
        CHECK_THROWS_AS(team.add(&ninja), std::runtime_error);
    }

    TEST_CASE("TEST 15: Character Hit Test (With Exceptions)")
    {
        //Point location(0, 0);
        Character character("John", Point(0, 0), 0);
        // Hitting a character with negative amount should throw an exception
        CHECK_THROWS_AS(character.hit(-10), std::runtime_error);
    }

    TEST_CASE("TEST 16: Cowboy Shoot Test With Exceptions")
    {
        Cowboy cowboy("John", Point(0, 0));
        // Shooting without bullets should throw an exception
        CHECK_THROWS_AS(cowboy.shoot(nullptr), std::runtime_error);
        // Reloading the cowboy's weapon
        cowboy.reload();
        // Shooting at a null enemy should throw an exception
        CHECK_THROWS_AS(cowboy.shoot(nullptr), std::runtime_error);
    }

    TEST_CASE("TEST 17: Cowboy Shoot Test")
    {
        Cowboy cowboy("John",Point(0, 0));
        Cowboy enemyCowboy("Tom", Point(3, 4));
        cowboy.reload();
        CHECK(cowboy.hasBullets());
        cowboy.shoot(&enemyCowboy);
        CHECK_FALSE(enemyCowboy.isAlive());
        CHECK_FALSE(cowboy.hasBullets());
    }

    TEST_CASE("TEST 18: Team2 StillAlive Test")
    {
        Team2 team;
        Cowboy cowboy("John", Point(0, 0));
        Ninja ninja("Ryu", Point(1, 1), 10);
        CHECK_EQ(team.stillAlive(), 0);
        team.add(&cowboy);
        CHECK_EQ(team.stillAlive(), 1);
        team.add(&ninja);
        CHECK_EQ(team.stillAlive(), 2);
        cowboy.hit(110);
        CHECK_EQ(team.stillAlive(), 1);
        ninja.hit(100);
        CHECK_EQ(team.stillAlive(), 0);
    }

    TEST_CASE("TEST 19: Ninja Slash Test")
    {
        Ninja ninja("Ryu", Point(0, 0), 10);
        Character enemy("Enemy", Point(1, 1), 110);
        ninja.slash(nullptr); // Slashing a null enemy should have no effect
        CHECK(enemy.isAlive());
        ninja.slash(&enemy);
        CHECK_FALSE(enemy.isAlive());
    }

    TEST_CASE("TEST 20: Check If Cowboy Has Bullets")
    {
        Cowboy cowboy("John", Point(0, 0));
        CHECK(cowboy.hasBullets() == false);
    }

} // namespace ariel
