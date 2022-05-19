    for (int i = 0; i < days_to_apply; i++){
        cout << (ptr+i)->date << "\n";
        cout << "  Transport cost (NZD) :\t" << (ptr+i)->transport_cost << "\n"; 
        cout << "  Meal cost (NZD) :\t\t" << (ptr+i)->meal_cost << "\n"; 
        cout << "  Entertainment cost (NZD) :\t" << (ptr+i)->entertainment_cost << "\n"; 
        cout << "  Others (NZD) :\t\t" << (ptr+i)->others << "\n\n"; 
    }