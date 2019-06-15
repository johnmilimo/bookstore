#include "unity/unity.h"
#include "book_store.h"

void test_only_a_single_book(void)
{
    int basket[] = {1};
    TEST_ASSERT_EQUAL_INT(800, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_of_the_same_book(void)
{
    int basket[] = {2, 2};
    TEST_ASSERT_EQUAL_INT(1600, total(basket, sizeof(basket)/sizeof(int)));
}

void test_empty_basket(void)
{
    int basket[] = {};
    TEST_ASSERT_EQUAL_INT(0, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_different_books(void)
{
    int basket[] = {1, 2};
    TEST_ASSERT_EQUAL_INT(1520, total(basket, sizeof(basket)/sizeof(int)));
}

void test_three_different_books(void)
{
    int basket[] = {1, 2, 3};
    TEST_ASSERT_EQUAL_INT(2160, total(basket, sizeof(basket)/sizeof(int)));
}

void test_four_different_books(void)
{
    int basket[] = {1, 2, 3, 4};
    TEST_ASSERT_EQUAL_INT(2560, total(basket, sizeof(basket)/sizeof(int)));
}

void test_five_different_books(void)
{
    int basket[] = {1, 2, 3, 4, 5};
    TEST_ASSERT_EQUAL_INT(3000, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_groups_of_4_is_cheaper_than_group_of_5_plus_group_of_3(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 5};
    TEST_ASSERT_EQUAL_INT(5120, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_groups_of_4_is_cheaper_than_groups_of_5_and_3(void)
{
    int basket[] = {1, 1, 2, 3, 4, 4, 5, 5};
    TEST_ASSERT_EQUAL_INT(5120, total(basket, sizeof(basket)/sizeof(int)));
}

void test_group_of_4_plus_group_of_2_is_cheaper_than_2_groups_of_3(void)
{
    int basket[] = {1, 1, 2, 2, 3, 4};
    TEST_ASSERT_EQUAL_INT(4080, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_each_of_first_4_books_and_1_copy_each_of_rest(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    TEST_ASSERT_EQUAL_INT(5560, total(basket, sizeof(basket)/sizeof(int)));
}

void test_two_copies_of_each_book(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    TEST_ASSERT_EQUAL_INT(6000, total(basket, sizeof(basket)/sizeof(int)));
}

void test_three_copies_of_first_book_and_2_each_of_remaining(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1};
    TEST_ASSERT_EQUAL_INT(6800, total(basket, sizeof(basket)/sizeof(int)));
}

void test_three_each_of_first_2_books_and_2_each_of_remaining_books(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 2};
    TEST_ASSERT_EQUAL_INT(7520, total(basket, sizeof(basket)/sizeof(int)));
}

void test_four_groups_of_4_are_cheaper_than_2_groups_each_of_5_and_3(void)
{
    int basket[] = {1, 1, 2, 2, 3, 3, 4, 5, 1, 1, 2, 2, 3, 3, 4, 5};
    TEST_ASSERT_EQUAL_INT(10240, total(basket, sizeof(basket)/sizeof(int)));
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_only_a_single_book);
    RUN_TEST(test_two_of_the_same_book);
    RUN_TEST(test_empty_basket);
    RUN_TEST(test_two_different_books);
    RUN_TEST(test_three_different_books);
    RUN_TEST(test_four_different_books);
    RUN_TEST(test_five_different_books);
    RUN_TEST(test_two_groups_of_4_is_cheaper_than_group_of_5_plus_group_of_3);
    RUN_TEST(test_two_groups_of_4_is_cheaper_than_groups_of_5_and_3);
    RUN_TEST(test_group_of_4_plus_group_of_2_is_cheaper_than_2_groups_of_3);
    RUN_TEST(test_two_each_of_first_4_books_and_1_copy_each_of_rest);
    RUN_TEST(test_two_copies_of_each_book);
    RUN_TEST(test_three_copies_of_first_book_and_2_each_of_remaining);
    RUN_TEST(test_three_each_of_first_2_books_and_2_each_of_remaining_books);
    RUN_TEST(test_four_groups_of_4_are_cheaper_than_2_groups_each_of_5_and_3);
    return UNITY_END();
}