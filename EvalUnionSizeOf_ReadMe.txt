EvalUnionSizeOf.cpp : Defines the entry point for the console application.
Developer: Paul Overstreet
Purpose	: This evaluation was written to test the behavior of a union with the sizeof() method.  A union
					assumes only one of the structures it contains.  Therefore, to be safe, Sizeof(myunion) should
					return the length of the largest struct the union contains (the variables, not the methods).
					For example:
						- Structure stOne has a single char variable with a size of 8 bytes.
						- Structure stTwo has two char variables each with a size of 10 bytes.
						- Structure stThree also has two char variables but each has a size of 2 bytes.
						- stTwo occupies more bytes in memory than either of the other structures.
						- Therefore, when all three structures are included in unAll, sizeof(unAll) should return the
							same as sizeof(stTwo).