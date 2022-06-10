#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
	std::string str = "DATAhalloweeksENDDATAhalloweeks meEND";
	
	bool FoundStartingTag = false, FoundEndingTag = false;
	std::string Value;
	
	for (int i = 0; i < str.size(); i++) {
		if (!FoundStartingTag) {
			if (str[i-3] == 'D' && str[i-2] == 'A' && str[i-1] == 'T' && str[i] == 'A') {
				FoundStartingTag = true;
			}
		} else {
			if (!FoundEndingTag) {
				if (str[i] == 'E' && str[i+1] == 'N' && str[i+2] == 'D') {
					FoundEndingTag = true;
				} else {
					Value += str[i];
				}
			} else {
				std::cout << "Value: " << Value << "\n";
				FoundStartingTag = false;
				FoundEndingTag = false;
				Value = "";
			}
		}
	}
    return 0;
}