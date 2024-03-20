int C, n, m;	// �Է�1
int a, b;		// �Է�2. m���� ���� ������ ���� ģ���� �� �л��� ��ȣ

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

// �� Sol 1�� ������
//		1. (0, 1) �� (1, 0)�� �ٸ� ������ ����Ѵ�. i = 0, j = 1 �� ����, i = 1, j = 0 �� ��츦 �ٸ��� ����Ѵ�.
//		2. { (0, 1), (2, 3) } �� { (2, 3), (0, 1} } �� �ٸ� ���̽��� ����Ѵ�.

// Solution 2. ���� ��ȣ�������� ������ �������Ѽ� �ذ�
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