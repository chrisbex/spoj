#include <iostream>
#include <math.h>

using namespace std;

float odleglosc(int x, int y)	{ return sqrt(x*x+y*y); }

int count_characters(char *text)
{
	int i = 0;
	while (text[i] != '\0') i++;
	return i;
}

class _record
{
	public:
		_record();
		_record(const _record &r) { memcpy(this->name, r.name, 10); this->x = r.x; this->y = r.y; this->len = r.len; }
		void count_len() { len = odleglosc(this->x, this->y); }
		bool operator == (const _record &n);
		bool operator > (const _record &n);
		bool operator < (const _record &n);

		char name[10];
		int x;
		int y;
		float len;
};

_record::_record()
{
	x = 0;
	y = 0;
	len = 0;
}

bool _record::operator == (const _record &n)
{
	if (this->len = n.len) return true;
	else return false;
}

bool _record::operator < (const _record &n)
{
	if (this->len < n.len) return true;
	else return false;
}

bool _record::operator > (const _record &n)
{
	if (this->len > n.len) return true;
	else return false;
}

_record* sort_records(_record *r, int ilosc_rekordow)
{
	_record temp;
	for (int j = 0; j < ilosc_rekordow - 1; j++)
	{
		for (int i = 0; i < ilosc_rekordow - 1; i++)
		{
			if (r[i+1] < r[i])
			{
				temp = r[i];
				r[i] = r[i+1];
				r[i+1] = temp;
			}
		}
	}
}



int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int ilosc_punktow, x, y;
		cin >> ilosc_punktow;
		_record *tab = new _record[ilosc_punktow];
		for (int k = 0; k < ilosc_punktow; k++)
		{
			cin >> tab[k].name >> tab[k].x >> tab[k].y;
			tab[k].count_len();
		}
		sort_records(tab, ilosc_punktow);
		for (int j = 0; j < ilosc_punktow; j++) cout << tab[j].name << " " << tab[j].x << " " << tab[j].y << endl;
		cout << endl;
	}
	return 0;
}