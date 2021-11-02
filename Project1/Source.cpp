#include <iostream>
#include <string>
using namespace std;

class Device
{
public:
	Device() {}
	int setVolume() {}
	int setChannel() {}
	int power() {}
	~Device() {}
};

class Remote
{
public:
	Remote() {}
	bool enable()
	{
		cout << "on!" << endl;
		return true;
	}
	bool disable()
	{
		cout << "off!" << endl;
		return false;
	}
	int nextChannel(int channel)
	{
		channel += 1;
		return channel;
	}
	int prevChannel(int channel)
	{
		channel -= 1;
		return channel;
	}
	int volumeUp(int volume)
	{
		volume += 1;
		return volume;
	}
	int volumeDown(int volume)
	{
		volume -= 1;
		return volume;
	}
	~Remote() {}
};

class Tv : public Device
{
private:
	bool power;
	int channel;
	int volume;
public:
	Tv(bool power, int channel, int volume)
	{
		this->power = power;
		this->channel = channel;
		this->volume = volume;
	}
	int powerStatus(bool status)
	{
		if (status == true)
		{
			Remote a;
			return a.enable();
		}
		else
		{
			Remote a;
			return a.disable();
		}
	}
	int setVolume(bool status)
	{
		if (status == true)
		{
			Remote a;
			volume = a.volumeUp(volume);
			return volume;
		}
		else
		{
			Remote a;
			volume = a.volumeDown(volume);
			if (volume < 0) volume = 0;
			return volume;
		}
	}
	int setChannel(bool status)
	{
		if (status == true)
		{
			Remote a;
			channel = a.nextChannel(channel);
			return channel;
		}
		else
		{
			Remote a;
			channel = a.prevChannel(channel);
			if (channel < 0) channel = 0;
			return channel;
		}
	}
	~Tv() {}
};

class Radio : public Device
{
private:
	bool power;
	int channel;
	int volume;
public:
	Radio(bool power, int channel, int volume)
	{
		this->power = power;
		this->channel = channel;
		this->volume = volume;
	}
	int powerStatus(bool status)
	{
		if (status == true)
		{
			Remote a;
			return a.enable();
		}
		else
		{
			Remote a;
			return a.disable();
		}
	}
	int setVolume(bool status)
	{
		if (status == true)
		{
			Remote a;
			volume = a.volumeUp(volume);
			return volume;
		}
		else
		{
			Remote a;
			volume = a.volumeDown(volume);
			if (volume < 0) volume = 0;
			return volume;
		}
	}
	int setChannel(bool status)
	{
		if (status == true)
		{
			Remote a;
			channel = a.nextChannel(channel);
			return channel;
		}
		else
		{
			Remote a;
			channel = a.prevChannel(channel);
			if (channel < 0) channel = 0;
			return channel;
		}
	}
	~Radio() {}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Device* device;
	Radio radio(false, 0, 0);
	Tv tv(false, 0, 0);
	int x;
	cout << "1 - включить тв" << endl;
	cout << "2 - включить радио" << endl;
	cin >> x;
	if (x == 1)
	{
		device = &tv;
		while (x < 4)
		{
			system("cls");
			tv.powerStatus(true);
			cout << "1 - сменить канал" << endl;
			cout << "2 - убавить/прибавить звук" << endl;
			cout << "3 - выключить тв" << endl;
			cin >> x;
			if (x == 1)
			{
				cout << "1 - на один вперед" << endl;
				cout << "0 - на один назад" << endl;
				int f;
				cin >> f;
				cout << endl;
				if (f == 1)
				{
					cout << "channel: " << tv.setChannel(true) << endl;
					system("pause");
				}
				if (f == 0)
				{
					cout << "channel: " << tv.setChannel(false) << endl;
					system("pause");
				}
			}
			if (x == 2)
			{
				cout << "1 - на один громче" << endl;
				cout << "0 - на один тише" << endl;
				int f;
				cin >> f;
				cout << endl;
				if (f == 1)
				{
					cout << "volume: " << tv.setVolume(true) << endl;
					system("pause");
				}
				if (f == 0)
				{
					cout << "volume: " << tv.setVolume(false) << endl;
					system("pause");
				}
			}
			if (x == 3)
			{
				tv.powerStatus(false);
				system("cls");
				return 0;
			}
		}
	}
	if (x == 2)
	{
		device = &radio;
		while (x < 4)
		{
			system("cls");
			tv.powerStatus(true);
			cout << "1 - сменить частоту" << endl;
			cout << "2 - убавить/прибавить звук" << endl;
			cout << "3 - выключить радио" << endl;
			cin >> x;
			if (x == 1)
			{
				cout << "1 - на один вперед" << endl;
				cout << "0 - на один назад" << endl;
				int f;
				cin >> f;
				cout << endl;
				if (f == 1)
				{
					cout << "channel: " << radio.setChannel(true) << endl;
					system("pause");
				}
				if (f == 0)
				{
					cout << "channel: " << radio.setChannel(false) << endl;
					system("pause");
				}
			}
			if (x == 2)
			{
				cout << "1 - на один громче" << endl;
				cout << "0 - на один тише" << endl;
				int f;
				cin >> f;
				cout << endl;
				if (f == 1)
				{
					cout << "volume: " << radio.setVolume(true) << endl;
					system("pause");
				}
				if (f == 0)
				{
					cout << "volume: " << radio.setVolume(false) << endl;
					system("pause");
				}
			}
			if (x == 3)
			{
				tv.powerStatus(false);
				system("cls");
				return 0;
			}
		}
	}
	return 0;
}