#include "plate.h"
#include <cctype>
#include <vector>

using namespace std;

//���ۨӷ�1
const string V8_type_list[30] =
{
	"���]�w",
	"�ۥΤp�ȡ]�f�^��", "���߻�ê�̱M�Ψ�", "����p�]�f�^�Ȩ�", "�ۥΤj�f��(�t�ۥΦ��ި�)", "�ۥΤj�Ȩ�",
	"��~�j�Ȩ�", "��~�j�f��(�t�f�B���ި�)", "��~�f�d���ި�", "��~�p�f��", "��~�p�Ȩ�", "�C����", "��q��",
	"���q��������", "��������", "�p����������", "�j����������", "550cc�H�W�j����������", "�ۥΩ쨮", "��~�쨮",
	"�q�ʯ���p�Ȩ�", "�q�ʨ��߻�ê�̱M�Ψ�", "�q�ʦۥΤp����", "�q�ʤj�Ȩ�(�t��~�Φۥ�)", "�q����~�p�Ȩ�",
	"�q�ʴ��q��������", "�q�ʻ�������", "�q�ʤp����������", "�q�ʤj����������", "�q��550cc�H�W�j����������"
};
const vector<pair<string, string>> V8_number_space_list[30] =
{
	/*���]�w*/{},
	/*�ۥΤp�ȡ]�f�^��*/{ {"AJF-0001", "DZZ-9999"}, {"FAA-0001", "GZZ-9999"}, {"UAA-0001", "VZZ-9999"} },
	/*���߻�ê�̱M�Ψ�*/{ {"WAC-0001", "WDZ-9999"}, {"WEF-0001", "WEZ-9999"} },
	/*����p�]�f�^�Ȩ�*/{ {"RAQ-0001", "RDZ-9999"}, {"RFA-0001", "RZZ-9999"}, {"REN-0001", "REZ-9999"} },
	/*�ۥΤj�f��(�t�ۥΦ��ި�)*/{ {"KEA-0001", "KHZ-9999"}, {"KSA-0001", "KSZ-9999"} },
	/*�ۥΤj�Ȩ�*/{ {"KJA-0001", "KJZ-9999"} },
	/*��~�j�Ȩ�*/{ {"KKA-0001", "KKZ-9999"} },
	/*��~�j�f��(�t�f�B���ި�)*/{ {"KLA-0001", "KMZ-9999"}, {"KRA-0001", "KRZ-9999"} },
	/*��~�f�d���ި�*/{ {"KNA-0001", "KNZ-9999"} },
	/*��~�p�f��*/{ {"KPA-0001", "KPZ-9999"}, {"KTA-0001", "KTZ-9999"} },
	/*��~�p�Ȩ�*/{ {"TAA-0001", "TZZ-9999"} },
	/*�C����*/{ {"KAA-0001", "KDZ-9999"} },
	/*��q��*/{ {"KQA-0001", "KQD-9999"} },
	/*���q��������*/{ {"MAY-0001", "PZZ-9999"}, {"JAA-0001", "JZZ-9999"}, {"XAA-0001", "ZZZ-9999"}, {"WFA-0001", "WZZ-9999"}, {"QNA-0001", "QZZ-9999"}, {"LNA-0001", "LZZ-9999"}, {"HEA-0001", "HZZ-9999"}, {"KUA-0001", "KZZ-9999"}, {"KQE-0001", "KQZ-9999"}, {"SFA-0001", "SZZ-9999"} },
	/*��������*/{ {"QAL-0001", "QMZ-9999"} },
	/*�p����������*/{ {"SAC-0001", "SEZ-9999"} },
	/*�j����������*/{ {"LAD-0001", "LFZ-9999"} },
	/*550cc�H�W�j����������*/{ {"LGA-0001", "LMZ-9999"} },
	/*�ۥΩ쨮*/{ {"HAA-0001", "HAZ-9999"} },
	/*��~�쨮*/{ {"HBA-0001", "HDZ-9999"} },
	/*�q�ʯ���p�Ȩ�*/{ {"REA-0001", "REM-9999"} },
	/*�q�ʨ��߻�ê�̱M�Ψ�*/{ {"WEA-0001", "WEE-9999"} },
	/*�q�ʦۥΤp����*/{ {"EAB-0001", "EAK-9999"} },
	/*�q�ʤj�Ȩ�(�t��~�Φۥ�)*/{ {"EAL-0001", "EAL-9999"} },
	/*�q����~�p�Ȩ�*/{ {"EAM-0001", "EAM-9999"} },
	/*�q�ʴ��q��������*/{ {"EMD-0001", "EVZ-9999"} },
	/*�q�ʻ�������*/{ {"EWA-0001", "EZM-9999"} },
	/*�q�ʤp����������*/{ {"EZN-0001", "EZZ-9999"} },
	/*�q�ʤj����������*/{ {"EMB-0001", "EMC-9999"} },
	/*�q��550cc�H�W�j����������*/{ {"EMA-0001", "EMA-9999"} }
};

void plate::process()
{
	reset();
	set_version();
	if (version == 8)
		set_type_V8();
}

void plate::reset()
{
	version = 0;
	vehicle_type = 0;
}

void plate::set_version()
{
	if (number.size() == 8 && number[3] == '-' 
		&& isupper(number[0]) && isupper(number[1]) && isupper(number[2]) 
		&& isdigit(number[4]) && isdigit(number[5]) && isdigit(number[6]) && isdigit(number[7])) {
		version = 8;
		return;
	}
	//unfinished
	version = -1;
}

void plate::set_type_V8() {
	for (int t1 = 1; t1 <= 29; t1++) {
		for (int t2 = 0; t2 < V8_number_space_list[t1].size(); t2++) {
			if (number >= V8_number_space_list[t1][t2].first && number <= V8_number_space_list[t1][t2].second) {
				vehicle_type = t1;
				return;
			}
		}
	}
	vehicle_type = -1;
}

istream& operator>>(std::istream& is, plate& p)
{
	is >> p.number;
	p.process();
	return is;
}

ostream& operator<<(std::ostream& os, plate& p)
{
	os << "���P���X: " << p.number << "\n";
	os << "���P����: " << p.version << "\n";
	os << "��������: ";
	if (p.version == 8) {
		if (p.vehicle_type > 0 && p.vehicle_type <= 29)
			os << V8_type_list[p.vehicle_type] << "\n";
		else
			os << "����\n";
	}
	else {
		os << "���䴩������\n";
	}
	os << endl;
	return os;
}







/*
�ӷ�:
1:https://www.thb.gov.tw/FileResource.axd?path=html%252Fdoc%252F%25E7%259B%25A3%25E7%2590%2586%25E6%25A5%25AD%25E5%258B%2599%252F%25E7%2589%258C%25E7%2585%25A7%252F%25E5%258E%259F%25E5%259E%258B%25E5%25BC%258F%25E3%2580%2581%25E6%2596%25B0%25E5%25BC%258F%25E3%2580%2581%25E3%2580%258C%25E4%25B8%2580%25E8%25BB%258A%25E4%25B8%2580%25E8%2599%259F%25E3%2580%258D%25E6%2596%25B0%25E7%25B7%25A8%25E7%25A2%25BC%25E6%2596%25B9%25E5%25BC%258F%25E8%2599%259F%25E7%2589%258C%25E5%258D%2580%25E5%2588%2586%25E5%25B0%258D%25E7%2585%25A7%25E8%25A1%25A8.pdf


*/