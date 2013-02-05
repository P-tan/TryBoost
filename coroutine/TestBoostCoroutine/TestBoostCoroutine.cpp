// TestBoostCoroutine.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <boost/coroutine/all.hpp>
#include <boost/foreach.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/bind.hpp>

typedef boost::dynamic_bitset<> dynbitset;
typedef boost::coroutines::coroutine<dynbitset()> coro_t;

using namespace std;

void f(coro_t::caller_type &ca, dynbitset &bs, size_t n)
{
	ca(bs);
	for(auto i = bs.find_first(); i != bs.npos; i = bs.find_next(i)){
		if(i < n){
			i = n;
			continue;
		}
		bs[i] = 0;
		f(ca, bs, i);
		bs[i] = 1;
	}
}

class all_subsets
{
	dynbitset m_org;
public:
	all_subsets(dynbitset org) : m_org(org){}

	void operator()(coro_t::caller_type &ca){
		f(ca, m_org, 0);
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	const dynbitset org(string("1110"));
	coro_t c(boost::bind(f, _1, org, 0));
	BOOST_FOREACH(const dynbitset bs, c){
		cout << bs << endl;
	}
	cout << endl;

	all_subsets sub(org);
	coro_t c2(sub);
	BOOST_FOREACH(dynbitset bs, c2){
		cout << bs << endl;
	}
	return 0;
}

