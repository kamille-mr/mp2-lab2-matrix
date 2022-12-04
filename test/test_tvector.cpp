#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length) {

	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector) {

	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length) {

	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector) {

	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(TDynamicVector<int> v_1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one) {

	TDynamicVector<int>v_1(5);
	TDynamicVector<int>v_2(v_1);
	EXPECT_EQ(v_1, v_2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory) {

	TDynamicVector<int>v_1(5);
	v_1[2] = 3;
	TDynamicVector<int>v_2(v_1);
	v_2[2] = 5;
	EXPECT_NE(v_1, v_2);
}

TEST(TDynamicVector, can_get_size) {

	TDynamicVector<int> v(5);
	EXPECT_EQ(5, v.size());
}


TEST(TDynamicVector, throws_when_set_element_with_negative_index) {

	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v[-10] = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index) {

	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v[10] = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself) {

	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(5);
	ASSERT_NO_THROW(v_1 = v_2);
}

TEST(TDynamicVector, assign_operator_change_vector_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	v_1 = v_2;
	EXPECT_EQ(10, v_1.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	ASSERT_NO_THROW(v_1 = v_2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(v_1);
	EXPECT_TRUE(v_1 == v_2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true) {

	TDynamicVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	EXPECT_FALSE(v_1 == v_2);
}

TEST(TDynamicVector, can_add_scalar_to_vector) {

	TDynamicVector<int> vector(3);
	TDynamicVector<int> res(3);
	vector[0] = 3;
	vector[1] = 3;
	vector[2] = 3;
	vector = vector + 3;
	res[0] = 6;
	res[1] = 6;
	res[2] = 6;
	EXPECT_EQ(res, vector);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector) {

	TDynamicVector<int> vector(3);
	TDynamicVector<int> res(3);
	vector[0] = 3;
	vector[1] = 3;
	vector[2] = 3;
	vector = vector - 3;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	EXPECT_EQ(res, vector);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector) {

	TDynamicVector<int> vector(3);
	TDynamicVector<int> res(3);
	vector[0] = 3;
	vector[1] = 3;
	vector[2] = 3;
	vector = vector * 3;
	res[0] = 9;
	res[1] = 9;
	res[2] = 9;
	EXPECT_EQ(res, vector);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(5);
	v_1[3] = 3;
	v_2[3] = 5;
	TDynamicVector<int> v = v_1 + v_2;
	TDynamicVector<int> res(5);
	res[3] = 8;
	EXPECT_EQ(res, v);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	EXPECT_ANY_THROW(v_1 + v_2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(5);
	v_1[3] = 10;
	v_2[3] = 5;
	TDynamicVector<int> v = v_1 - v_2;
	TDynamicVector<int> res(5);
	res[3] = 5;
	EXPECT_EQ(res, v);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	EXPECT_ANY_THROW(v_1 - v_2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(5);
	v_1[3] = 3;
	v_2[3] = 3;
	int v = v_1 * v_2;
	int res = 9;
	EXPECT_EQ(res, v);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size) {

	TDynamicVector<int> v_1(5);
	TDynamicVector<int> v_2(10);
	EXPECT_ANY_THROW(v_1 * v_2);
}

TEST(TDynamicVector, can_move_vectors){

	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(TDynamicVector<int> v_2(std::move(v)));
}

TEST(TDynamicVector, moved_vector_is_equal_to_source_one){

	TDynamicVector<int> v_1(5);
	v_1[3] = 3;
	TDynamicVector<int> v_2(5);
	v_2[3] = 3;
	TDynamicVector<int> res(std::move(v_1));
	ASSERT_EQ(res, v_2);
}
