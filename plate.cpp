#include "plate.h"
#include <cctype>
#include <vector>

using namespace std;

//取自來源1
const string V8_type_list[30] =
{
	"未設定",
	"自用小客（貨）車", "身心障礙者專用車", "租賃小（貨）客車", "自用大貨車(含自用曳引車)", "自用大客車",
	"營業大客車", "營業大貨車(含貨運曳引車)", "營業貨櫃曳引車", "營業小貨車", "營業小客車", "遊覽車", "交通車",
	"普通重型機車", "輕型機車", "小型輕型機車", "大型重型機車", "550cc以上大型重型機車", "自用拖車", "營業拖車",
	"電動租賃小客車", "電動身心障礙者專用車", "電動自用小型車", "電動大客車(含營業及自用)", "電動營業小客車",
	"電動普通重型機車", "電動輕型機車", "電動小型輕型機車", "電動大型重型機車", "電動550cc以上大型重型機車"
};
const vector<pair<string, string>> V8_number_space_list[30] =
{
	/*未設定*/{},
	/*自用小客（貨）車*/{ {"AJF-0001", "DZZ-9999"}, {"FAA-0001", "GZZ-9999"}, {"UAA-0001", "VZZ-9999"} },
	/*身心障礙者專用車*/{ {"WAC-0001", "WDZ-9999"}, {"WEF-0001", "WEZ-9999"} },
	/*租賃小（貨）客車*/{ {"RAQ-0001", "RDZ-9999"}, {"RFA-0001", "RZZ-9999"}, {"REN-0001", "REZ-9999"} },
	/*自用大貨車(含自用曳引車)*/{ {"KEA-0001", "KHZ-9999"}, {"KSA-0001", "KSZ-9999"} },
	/*自用大客車*/{ {"KJA-0001", "KJZ-9999"} },
	/*營業大客車*/{ {"KKA-0001", "KKZ-9999"} },
	/*營業大貨車(含貨運曳引車)*/{ {"KLA-0001", "KMZ-9999"}, {"KRA-0001", "KRZ-9999"} },
	/*營業貨櫃曳引車*/{ {"KNA-0001", "KNZ-9999"} },
	/*營業小貨車*/{ {"KPA-0001", "KPZ-9999"}, {"KTA-0001", "KTZ-9999"} },
	/*營業小客車*/{ {"TAA-0001", "TZZ-9999"} },
	/*遊覽車*/{ {"KAA-0001", "KDZ-9999"} },
	/*交通車*/{ {"KQA-0001", "KQD-9999"} },
	/*普通重型機車*/{ {"MAY-0001", "PZZ-9999"}, {"JAA-0001", "JZZ-9999"}, {"XAA-0001", "ZZZ-9999"}, {"WFA-0001", "WZZ-9999"}, {"QNA-0001", "QZZ-9999"}, {"LNA-0001", "LZZ-9999"}, {"HEA-0001", "HZZ-9999"}, {"KUA-0001", "KZZ-9999"}, {"KQE-0001", "KQZ-9999"}, {"SFA-0001", "SZZ-9999"} },
	/*輕型機車*/{ {"QAL-0001", "QMZ-9999"} },
	/*小型輕型機車*/{ {"SAC-0001", "SEZ-9999"} },
	/*大型重型機車*/{ {"LAD-0001", "LFZ-9999"} },
	/*550cc以上大型重型機車*/{ {"LGA-0001", "LMZ-9999"} },
	/*自用拖車*/{ {"HAA-0001", "HAZ-9999"} },
	/*營業拖車*/{ {"HBA-0001", "HDZ-9999"} },
	/*電動租賃小客車*/{ {"REA-0001", "REM-9999"} },
	/*電動身心障礙者專用車*/{ {"WEA-0001", "WEE-9999"} },
	/*電動自用小型車*/{ {"EAB-0001", "EAK-9999"} },
	/*電動大客車(含營業及自用)*/{ {"EAL-0001", "EAL-9999"} },
	/*電動營業小客車*/{ {"EAM-0001", "EAM-9999"} },
	/*電動普通重型機車*/{ {"EMD-0001", "EVZ-9999"} },
	/*電動輕型機車*/{ {"EWA-0001", "EZM-9999"} },
	/*電動小型輕型機車*/{ {"EZN-0001", "EZZ-9999"} },
	/*電動大型重型機車*/{ {"EMB-0001", "EMC-9999"} },
	/*電動550cc以上大型重型機車*/{ {"EMA-0001", "EMA-9999"} }
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
	os << "車牌號碼: " << p.number << "\n";
	os << "車牌版本: " << p.version << "\n";
	os << "車輛類型: ";
	if (p.version == 8) {
		if (p.vehicle_type > 0 && p.vehicle_type <= 29)
			os << V8_type_list[p.vehicle_type] << "\n";
		else
			os << "未知\n";
	}
	else {
		os << "不支援此版本\n";
	}
	os << endl;
	return os;
}







/*
來源:
1:https://www.thb.gov.tw/FileResource.axd?path=html%252Fdoc%252F%25E7%259B%25A3%25E7%2590%2586%25E6%25A5%25AD%25E5%258B%2599%252F%25E7%2589%258C%25E7%2585%25A7%252F%25E5%258E%259F%25E5%259E%258B%25E5%25BC%258F%25E3%2580%2581%25E6%2596%25B0%25E5%25BC%258F%25E3%2580%2581%25E3%2580%258C%25E4%25B8%2580%25E8%25BB%258A%25E4%25B8%2580%25E8%2599%259F%25E3%2580%258D%25E6%2596%25B0%25E7%25B7%25A8%25E7%25A2%25BC%25E6%2596%25B9%25E5%25BC%258F%25E8%2599%259F%25E7%2589%258C%25E5%258D%2580%25E5%2588%2586%25E5%25B0%258D%25E7%2585%25A7%25E8%25A1%25A8.pdf


*/