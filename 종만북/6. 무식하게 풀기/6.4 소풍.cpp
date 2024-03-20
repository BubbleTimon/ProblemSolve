int C, n, m;	// 입력1
int a, b;		// 입력2. m개의 정수 쌍으로 서로 친구인 두 학생의 번호

bool taken[10];
bool areFriends[10][10];

// Solution 1.
int CountPairings1(bool taken[10])
{
	bool finished = true;
	for (bool paired : taken)
		if (!paired)
			finished = false;

	if (finished)
		return 1;

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!taken[i] && !taken[j] && areFriends[i][j])
			{
				taken[i] = taken[j] = true;
				ret += CountPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}

	return ret;
}

// ㅇ Sol 1의 문제점
//		1. (0, 1) 과 (1, 0)을 다른 쌍으로 취급한다. i = 0, j = 1 인 경우와, i = 1, j = 0 인 경우를 다르게 취급한다.
//		2. { (0, 1), (2, 3) } 과 { (2, 3), (0, 1} } 을 다른 케이스로 취급한다.

// Solution 2. 낮은 번호에서부터 순서를 강제시켜서 해결
bool CountPairings2(bool taken[10])
{
	int now = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			now = i;
			break;
		}
	}

	if (now == -1)
		return 1;

	int ret = 0;

	for (int next = now + 1; next < n; next++)
	{
		if (!taken[next] && areFriends[now][next])
		{
			taken[now] = taken[next] = true;
			ret += CountPairings(taken);
			taken[now] = taken[next] = false;
		}
	}

	return ret;
}