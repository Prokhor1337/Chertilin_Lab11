#include <iostream>
#include <string>
#include <regex>
#include <windows.h>

using namespace std;

struct Item {
private:
    string name;
    string category;
    string SKU;

public:
    Item(string itemName, string itemCategory, string itemSKU)
        : name(itemName), category(itemCategory), SKU(itemSKU) {}

    bool validateSKUAndExtractSupplierCode(string& supplierCode) {
        regex skuPattern("^([A-Z]{3}-\\d{4})-([A-Z0-9]{5})$");
        smatch matches;

        if (regex_match(SKU, matches, skuPattern)) {
            if (matches.size() == 3) {
                supplierCode = matches[2];
                return true;
            }
        }
        return false;
    }

    void printItemDetails() const {
        cout << "Назва: " << name << "\nКатегорія: " << category << "\nSKU: " << SKU << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Item myItem("Ноутбук", "Електроніка", "ABC-1234-XYZ12");

    string supplierCode;
    if (myItem.validateSKUAndExtractSupplierCode(supplierCode)) {
        cout << "SKU валідний. Код постачальника: " << supplierCode << endl;
    }
    else {
        cout << "SKU недійсний." << endl;
    }

    myItem.printItemDetails();

    return 0;
}
