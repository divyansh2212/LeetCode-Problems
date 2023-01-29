class LFUCache
{
	public:
		int cap;
	int cur_size = 0;
	int least_level = 0;
	map<int, list<pair<int, int>>> freq_store;
	map<int, list<pair<int, int>>::iterator > mp;
	map<int, int> levels;
	LFUCache(int capacity)
	{
		cap = capacity;
	}

	int get(int key)
	{
		if (!mp.count(key))
		{
			return -1;
		}

		int value = mp[key]->second;
		int cur_level = levels[key];
		auto it = mp[key];
		freq_store[cur_level].erase(it);
		if (least_level == cur_level and freq_store[cur_level].size() == 0)
		{
			least_level = cur_level + 1;
		}

		freq_store[cur_level + 1].push_back({ key, value });
		auto bk = prev(freq_store[cur_level + 1].end());
		mp[key] = bk;
		levels[key] = cur_level + 1;

		return value;
	}

	void put(int key, int value)
	{
		if (cap == 0)
		{
			return;
		}

		if (mp.count(key))
		{
			int cur_level = levels[key];
			auto it = mp[key];
			freq_store[cur_level].erase(it);
			if (least_level == cur_level and freq_store[cur_level].size() == 0)
			{
				least_level = cur_level + 1;
			}

			freq_store[cur_level + 1].push_back({ key, value });

			auto bk = prev(freq_store[cur_level + 1].end());
			mp[key] = bk;
			levels[key] = cur_level + 1;
		}
		else
		{
			if (cur_size == cap)
			{
				auto head_key = freq_store[least_level].begin()->first;
				mp.erase(head_key);
				freq_store[least_level].pop_front();	
			}
			else
			{
				cur_size++;
			}
            freq_store[0].push_back({ key, value });
			least_level = 0;
			auto bk = prev(freq_store[0].end());
			mp[key] = bk;
			levels[key] = 0;
		}
	}
};