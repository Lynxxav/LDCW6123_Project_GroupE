#include <iostream>
#include <string>
using namespace std;

int main() {
    char category;         // F = fashion, G = groceries, E = electronics
    double budget;         // user budget
    char choice, addMore;  // product and extra choices
    double spent = 0;      // total before discount
    double discount = 0;   // discount rate
    double finalPrice = 0; // total after discount
    double lastAddon = 0;  // track last add-on price
    double mainProduct = 0;  // store main product price

    cout << "=== Shopee Assistant ===" << endl;

    // Ask for category
    cout << "Enter category [F = Fashion, G = Groceries, E = Electronics]: ";
    cin >> category;

    // Ask for budget depending on category
    if (category == 'F' || category == 'f') {
        cout << "Enter your budget (RM0 - RM200): ";
    } 
    else if (category == 'G' || category == 'g') {
        cout << "Enter your budget (RM30 - RM150): ";
    } 
    else if (category == 'E' || category == 'e') {
        cout << "Enter your budget (RM50 - RM500): ";
    }
    else {
        cout << "Category not available.\n";
        return 0;
    }
    cin >> budget;

    // ==========================
    // FASHION SECTION
    // ==========================
    if (category == 'F' || category == 'f') {
        discount = 0.10; // fashion gets 10% discount

        if (budget >= 100) {
            cout << "Choose product: [A = Shirt RM80, B = Dress RM98]: ";
            cin >> choice;

            if (choice == 'A' || choice == 'a') {
                mainProduct = 80;     // store main product price
                spent += mainProduct; // add to total spent
                cout << "Product added: Shirt (RM80)\n";
            } 
            else if (choice == 'B' || choice == 'b') {
                mainProduct = 98;
                spent += mainProduct;
                cout << "Product added: Dress (RM98)\n";
            } 

            cout << "Do you want to add more items? [Y/N]: ";
            cin >> addMore;

            if (addMore == 'Y' || addMore == 'y') {
                cout << "Choose extra: [A = Shoes RM70, B = Accessories (RM9-35)]: ";
                cin >> choice;

                if (choice == 'A' || choice == 'a') {
                    spent += 70;
                    lastAddon = 70;
                    cout << "Added item: Shoes (RM70)\n";

                    cout << "Do you want to include Socks (+RM5)? [Y/N]: ";
                    char sockChoice;
                    cin >> sockChoice;
                    if (sockChoice == 'Y' || sockChoice == 'y') {
                        spent += 5;
                        lastAddon = 5; // socks are last addon
                        cout << "Added: Socks (RM5)\n";
                    }
                } 
                else if (choice == 'B' || choice == 'b') {
                    cout << "Accessories options: [A = Ring RM9, B = Bracelet RM15, C = Necklace RM25, D = Full Set RM35]: ";
                    char accChoice;
                    cin >> accChoice;

                    if (accChoice == 'A' || accChoice == 'a') { spent += 9; lastAddon = 9; cout << "Added: Ring (RM9)\n"; }
                    else if (accChoice == 'B' || accChoice == 'b') { spent += 15; lastAddon = 15; cout << "Added: Bracelet (RM15)\n"; }
                    else if (accChoice == 'C' || accChoice == 'c') { spent += 25; lastAddon = 25; cout << "Added: Necklace (RM25)\n"; }
                    else if (accChoice == 'D' || accChoice == 'd') { spent += 35; lastAddon = 35; cout << "Added: Full Set (RM35)\n"; }
                }
            }
        }

        else if (budget >= 50) {
            cout << "Choose product: [A = T-shirt RM50, B = Pants RM75, C = Shoes RM70]: ";
            cin >> choice;

            if (choice == 'A' || choice == 'a') { 
                mainProduct = 50; 
                spent += mainProduct; 
                cout << "Product added: T-shirt (RM50)\n"; 
            }
            else if (choice == 'B' || choice == 'b') { 
                mainProduct = 75; 
                spent += mainProduct; 
                cout << "Product added: Pants (RM75)\n"; 
            }
            else if (choice == 'C' || choice == 'c') { 
                mainProduct = 70;
                spent += mainProduct;
                cout << "Product added: Shoes (RM70)\n"; 

                cout << "Do you want to include Socks (+RM5)? [Y/N]: ";
                char sockChoice;
                cin >> sockChoice;
                if (sockChoice == 'Y' || sockChoice == 'y') {
                    spent += 5;
                    lastAddon = 5; // socks are last addon
                    cout << "Added: Socks (RM5)\n";
                }
            }
        }

        else {
            cout << "Tight budget! Only balance: RM" << budget << endl;
        }
    }

    // ==========================
    // GROCERIES SECTION
    // ==========================
    else if (category == 'G' || category == 'g') {
        discount = 0.05; // groceries get 5% discount

        if (budget >= 100) { // Premium Pack
            mainProduct = 100;
            spent += mainProduct;
            cout << "Product added: Premium Weekly Grocery Pack (RM100)\n";

            cout << "Do you want to add Snack (RM10)? [Y/N]: ";
            cin >> addMore;
            if (addMore == 'Y' || addMore == 'y') {
                spent += 10;
                lastAddon = 10;
                cout << "Added: Snack (RM10)\n";
            }

            cout << "Do you want to add Dessert (RM15)? [Y/N]: ";
            cin >> addMore;
            if (addMore == 'Y' || addMore == 'y') {
                spent += 15;
                lastAddon = 15;
                cout << "Added: Dessert (RM15)\n";
            }
        }
        else if (budget >= 50) { // Standard Pack
            mainProduct = 50;
            spent += mainProduct;
            cout << "Product added: Standard Grocery Pack (RM50)\n";

            if (budget > mainProduct) { // can afford at least one add-on
                cout << "You have extra budget! Choose add-on: [A = Snack RM10, B = Dessert RM15, N = None]: ";
                char addonChoice;
                cin >> addonChoice;

                if ((addonChoice == 'A' || addonChoice == 'a') && budget >= mainProduct + 10) {
                    spent += 10;
                    lastAddon = 10;
                    cout << "Added: Snack (RM10)\n";
                } 
                else if ((addonChoice == 'B' || addonChoice == 'b') && budget >= mainProduct + 15) {
                    spent += 15;
                    lastAddon = 15;
                    cout << "Added: Dessert (RM15)\n";
                } 
                else {
                    cout << "No add-ons selected or insufficient budget.\n";
                }
            }
        }
        else if (budget >= 30) { // Snack Bundle
            mainProduct = 30;
            spent += mainProduct;
            cout << "Product added: Snack Bundle (RM30)\n";
        }
        else {
            cout << "Tight budget! Only balance: RM" << budget << endl;
        }
    }

    // ==========================
    // ELECTRONICS SECTION 
    // ==========================
    else if (category == 'E' || category == 'e') {
        discount = 0.15; // 15% discount 

        if (budget >= 400) { // Premium Electronics
            cout << "Choose product: [A = Smartphone RM399, B = Laptop RM450]: ";
            cin >> choice;

            if (choice == 'A' || choice == 'a') {
                mainProduct = 399;
                spent += mainProduct;
                cout << "Product added: Smartphone (RM399)\n";
            } 
            else if (choice == 'B' || choice == 'b') {
                mainProduct = 450;
                spent += mainProduct;
                cout << "Product added: Laptop (RM450)\n";
            }

            cout << "Do you want to add accessories? [Y/N]: ";
            cin >> addMore;

            if (addMore == 'Y' || addMore == 'y') {
                cout << "Choose accessory: [A = Power Bank RM50, B = Wireless Earphones RM80, C = Phone Case RM25]: ";
                cin >> choice;

                if (choice == 'A' || choice == 'a') {
                    spent += 50;
                    lastAddon = 50;
                    cout << "Added: Power Bank (RM50)\n";

                    cout << "Do you want to add USB Cable (+RM15)? [Y/N]: ";
                    char cableChoice;
                    cin >> cableChoice;
                    if (cableChoice == 'Y' || cableChoice == 'y') {
                        spent += 15;
                        lastAddon = 15;
                        cout << "Added: USB Cable (RM15)\n";
                    }
                } 
                else if (choice == 'B' || choice == 'b') {
                    spent += 80;
                    lastAddon = 80;
                    cout << "Added: Wireless Earphones (RM80)\n";
                } 
                else if (choice == 'C' || choice == 'c') {
                    spent += 25;
                    lastAddon = 25;
                    cout << "Added: Phone Case (RM25)\n";

                    cout << "Do you want to add Screen Protector (+RM10)? [Y/N]: ";
                    char protectorChoice;
                    cin >> protectorChoice;
                    if (protectorChoice == 'Y' || protectorChoice == 'y') {
                        spent += 10;
                        lastAddon = 10;
                        cout << "Added: Screen Protector (RM10)\n";
                    }
                }
            }
        }

        else if (budget >= 200) { // Mid-range Electronics
            cout << "Choose product: [A = Tablet RM250, B = Smart Watch RM180, C = Gaming Headset RM120]: ";
            cin >> choice;

            if (choice == 'A' || choice == 'a') {
                mainProduct = 250;
                spent += mainProduct;
                cout << "Product added: Tablet (RM250)\n";

                cout << "Do you want to add Tablet Case (+RM30)? [Y/N]: ";
                char caseChoice;
                cin >> caseChoice;
                if (caseChoice == 'Y' || caseChoice == 'y') {
                    spent += 30;
                    lastAddon = 30;
                    cout << "Added: Tablet Case (RM30)\n";
                }
            } 
            else if (choice == 'B' || choice == 'b') {
                mainProduct = 180;
                spent += mainProduct;
                cout << "Product added: Smart Watch (RM180)\n";

                cout << "Do you want to add Watch Strap (+RM20)? [Y/N]: ";
                char strapChoice;
                cin >> strapChoice;
                if (strapChoice == 'Y' || strapChoice == 'y') {
                    spent += 20;
                    lastAddon = 20;
                    cout << "Added: Watch Strap (RM20)\n";
                }
            } 
            else if (choice == 'C' || choice == 'c') {
                mainProduct = 120;
                spent += mainProduct;
                cout << "Product added: Gaming Headset (RM120)\n";

                cout << "Do you want to add Microphone Stand (+RM25)? [Y/N]: ";
                char micChoice;
                cin >> micChoice;
                if (micChoice == 'Y' || micChoice == 'y') {
                    spent += 25;
                    lastAddon = 25;
                    cout << "Added: Microphone Stand (RM25)\n";
                }
            }
        }

        else if (budget >= 50) { // Budget Electronics
            cout << "Choose product: [A = Bluetooth Speaker RM60, B = USB Mouse RM35, C = Phone Charger RM25]: ";
            cin >> choice;

            if (choice == 'A' || choice == 'a') {
                mainProduct = 60;
                spent += mainProduct;
                cout << "Product added: Bluetooth Speaker (RM60)\n";
            } 
            else if (choice == 'B' || choice == 'b') {
                mainProduct = 35;
                spent += mainProduct;
                cout << "Product added: USB Mouse (RM35)\n";

                cout << "Do you want to add Mouse Pad (+RM8)? [Y/N]: ";
                char padChoice;
                cin >> padChoice;
                if (padChoice == 'Y' || padChoice == 'y') {
                    spent += 8;
                    lastAddon = 8;
                    cout << "Added: Mouse Pad (RM8)\n";
                }
            } 
            else if (choice == 'C' || choice == 'c') {
                mainProduct = 25;
                spent += mainProduct;
                cout << "Product added: Phone Charger (RM25)\n";
            }
        }

        else {
            cout << "Tight budget! Only balance: RM" << budget << endl;
        }
    }

    // ==========================
    // FINAL CHECKOUT
    // ==========================
    if (spent > 0) {
        finalPrice = spent - (spent * discount);

        cout << "\n--- Checkout Summary ---\n";
        cout << "Total before discount: RM" << spent << endl;
        cout << "Discount applied: -" << (spent * discount) << endl;
        cout << "Final price: RM" << finalPrice << endl;
        cout << "Your budget: RM" << budget << endl;

        if (finalPrice <= budget) {
            cout << "[OK] Purchase successful! Balance left: RM" << (budget - finalPrice) << endl;
        } else {
            double shortfall = finalPrice - budget;
            cout << "[X] You are short by RM" << shortfall << ".\n";
            cout << "Do you want to Cancel (C) last add-on or Top up (T)? ";
            char decision;
            cin >> decision;

            if (decision == 'T' || decision == 't') {
                double topup;
                cout << "Enter top up amount: RM";
                cin >> topup;
                budget += topup;

                if (budget >= finalPrice) {
                    cout << "Top up successful! [OK] Purchase complete.\n";
                    cout << "New balance left: RM" << (budget - finalPrice) << endl;
                } else {
                    cout << "Still not enough even after top up.\n";
                }
            } else {
                cout << "All add-ons removed. Proceeding with main order only.\n";

                spent = mainProduct; // reset spent to only main product
                finalPrice = spent - (spent * discount);

                cout << "\n--- Updated Checkout ---\n";
                cout << "Total before discount: RM" << spent << endl;
                cout << "Discount applied: -" << (spent * discount) << endl;
                cout << "Final price: RM" << finalPrice << endl;
                cout << "[OK] Purchase successful! Balance left: RM" << (budget - finalPrice) << endl;
            }
        }
    }

    cout << "\nThank you for shopping with Shopee!" << endl;
    return 0;
}