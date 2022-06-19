#include "board.h"
#include "board.c"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

static FILE* temp_file = NULL;

void test_countNeighbours(void)
{
    board *b = init_board(100, 200);
    CU_ASSERT_PTR_NULL(countNeighbours(b, 3, 5));
}

void test_evolve_board(void)
{
    board *b = init_board(100, 200);
    evolve_board(b);
    CU_ASSERT(b->isBuffer1 == b->isBuffer1);
}

void test_free_board(void) {
    board *b = init_board(100, 200);
    free_board(b);
    CU_ASSERT_NOT_EQUAL(b, NULL);
}

int init_suite1(void)
{
    if (NULL == (temp_file = fopen("temp.txt", "w+")))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int clean_suite1(void)
{
    if (0 != fclose(temp_file))
    {
        return -1;
    }
    else
    {
        temp_file = NULL;
        return 0;
    }
}

int main()
{
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of fprintf()", test_countNeighbours)) ||
       (NULL == CU_add_test(pSuite, "test of fread()", test_evolve_board)) ||
       (NULL == CU_add_test(pSuite, "test of fread()", test_free_board))
       )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}