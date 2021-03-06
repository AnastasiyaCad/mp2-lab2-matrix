#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(1);
	v[0] = 10;
	TVector<int> v1(v);
	ASSERT_TRUE(v == v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(1);
	TVector<int> v1(v);
	v[0] = 1;
	EXPECT_EQ(v1[0], 0);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
  ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[10]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_TRUE(v == v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int Size = 2;
	TVector<int> v(Size), v1(Size);
	for (int i = 0; i < Size; i++)
	{
		v1[i] = i;
	}
	v = v1;
	ASSERT_TRUE(v == v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int size1 = 2, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int Size1 = 5, Size2 = 7;
	TVector<int> v1(Size1), v2(Size2);
	for (int i = 0; i < Size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(5, v2.GetSize());
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	int size = 6;
	TVector<int> v(size);
	for (int i = 0; i < size; i++)
		v[i] = i;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	int size1 = 6, size2 = 10;
	TVector<int> v1(size1), v2(size2);
	ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(3);
	v1 = v1 + 5;
	ASSERT_TRUE(v1[0], 5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int size = 3;
	TVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 7;
	}
	v1 = v1 - 5;
	ASSERT_TRUE(v1[0], 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int size = 3;
	TVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 2;
	}
	v1 = v1 * 3;
	ASSERT_TRUE(v1[0], 6);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int size = 3;
	TVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v1 = v1 + v2;
	ASSERT_TRUE(v1[0], 3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	int size1 = 3, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = 2;
	}
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int size = 3;
	TVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 3;
		v2[i] = 1;
	}
	v1 = v1 - v2;
	ASSERT_TRUE(v1[0], 2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	int size1 = 5, size2 = 3;
	TVector<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int size = 3;
	TVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = 3;
		v2[i] = 1;
	}
	ASSERT_TRUE(v1 * v2, 3);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int size1 = 5, size2 = 3;
	TVector<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 * v2);
}
