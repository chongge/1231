/*************************************************************************
	> File Name: edit_distance.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 31 Dec 2014 02:57:57 PM CST
 ************************************************************************/

#include<iostream>
namespace NM
{
	struct Editdistance
	{
		int operator()(const std::string& src, const std::string& dest)
		{
				int** pp = new int*[dest.length() + 1]() ;
				int index, res, i, j ;
				int val_i,val_d ,val_r ;
				for(index = 0; index <= dest.length(); index ++)
				{
					pp[index] = new int[src.length() + 1]() ;
				}

				for(index = 0; index <= dest.length(); index ++)
				{
					pp[index][0] = index ;
				}

				for(index = 0; index <= src.length(); index ++)
				{
					pp[0][index] = index ;
				}
				for(i = 1; i <= dest.length(); i ++)
				{
					for(j = 1; j <= src.length(); j ++)
					{
						val_i = pp[i - 1][j] + 1 ;
						val_d = pp[i][j - 1] + 1;
						val_r = pp[i - 1][j - 1] + (src[j - 1] == dest[i - 1] ? 0: 1 );
						pp[i][j] = triple_min(val_i, val_d, val_r);
					//	std::cout << pp[i][j] << " " ;
					}
				//	std::cout << std::endl ;
				}

				res = pp[dest.length()][src.length()];
				for(index = 0; index <= dest.length(); index ++)
				{
					delete [] pp[index] ;
				}

				delete [] pp ;

				return res ;
		}
		int triple_min(int a, int b, int c)//2 4 5
		{
			return a < b ?(a < c? a : c):(b < c ? b : c);
		}
	};
}
int main(int argc, char* argv[])
{
	std::string src, dest ;
	NM::Editdistance ed ;
	while(std::cin >> src >> dest)
	{
		std::cout << src << "->" << dest << ": " << ed(src, dest) << std::endl ;
	}
	return 0 ;
}
