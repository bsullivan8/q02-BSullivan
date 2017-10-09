/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPiece_1x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_NE(x, Blank );
}
TEST(PiezasTest, dropPiece_2x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_NE(x, Blank );
}
TEST(PiezasTest, dropPiece_3x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_NE(x, Blank );
}
TEST(PiezasTest, dropPiece_4x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_EQ(x, Invalid );
}
TEST(PiezasTest, invalid_COl)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS);
	ASSERT_EQ(x, Invalid );
}
TEST(PiezasTest, changePiece_1x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_NE(x, X );
}
TEST(PiezasTest, changePiece_2x)
{
	char x;
	Piezas test;
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	x= test.dropPiece(BOARD_COLS-2);
	ASSERT_NE(x, O );
}
TEST(PiezasTest, fillBoard)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			x=test.dropPiece(i);
	ASSERT_EQ(x, O );
}
TEST(PiezasTest, checkBlank)
{
	char x;
	Piezas test;
	x = test.pieceAt(1,1);
	ASSERT_EQ(x, Blank );
}
TEST(PiezasTest, spotfilled_X)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			x=test.dropPiece(i);
	x = test.pieceAt(1,1);
	ASSERT_EQ(x, X );
}
TEST(PiezasTest, spotfilled_O)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			x=test.dropPiece(i);
	x = test.pieceAt(1,0);
	ASSERT_EQ(x, O );
}
TEST(PiezasTest, check_Xwin)
{
	char x;
	Piezas test;
	 test.dropPiece(0);
	 test.dropPiece(0);
	 test.dropPiece(1);
	 test.dropPiece(0);
	 test.dropPiece(1);
	 test.dropPiece(1);
	 test.dropPiece(2);
	 test.dropPiece(2);
	 test.dropPiece(2);
	 test.dropPiece(3);
	 test.dropPiece(3);
	 test.dropPiece(3);
	x = test.gameState();
	ASSERT_EQ(x,X );
}
TEST(PiezasTest, check_Owin)
{
	char x;
	Piezas test;
	 test.dropPiece(0);
	 test.dropPiece(1);
	 test.dropPiece(1);
	 test.dropPiece(2);
	 test.dropPiece(1);
	 test.dropPiece(3);
	 test.dropPiece(0);
	 test.dropPiece(2);
	 test.dropPiece(2);
	 test.dropPiece(0);
	 test.dropPiece(3);
	 test.dropPiece(3);
	x = test.gameState();
	ASSERT_EQ(x,O );
}
TEST(PiezasTest, testReset)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			test.dropPiece(i);
	test.reset();
	x = test.pieceAt(1,0);
	ASSERT_EQ(x, Blank );
}
TEST(PiezasTest, test_turnreset)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			x=test.dropPiece(i);
	test.reset();
	x=test.dropPiece(0);
	x=test.dropPiece(0);
	x = test.pieceAt(1,0);
	ASSERT_EQ(x, O );
}
TEST(PiezasTest, check_Nowin)
{
	char x;
	Piezas test;
	x = test.gameState();
	ASSERT_EQ(x, Invalid );
}
TEST(PiezasTest, check_tie)
{
	char x;
	Piezas test;
	for(int i=0; i<BOARD_COLS;i++)
		for(int j=0;j<BOARD_ROWS;j++)
			x=test.dropPiece(i);
	x = test.gameState();
	ASSERT_EQ(x, Blank );
}
