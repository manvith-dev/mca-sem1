#include <iostream>

struct Product {
  int PId;
  std::string PName;
  float Price;
};

Product PRODUCTS[] = {

    {1001, "Wireless Mouse", 599.00},
    {1002, "Mechanical Keyboard", 2499.00},
    {1003, "USB-C Cable", 399.00},
    {1004, "Laptop Stand", 1299.00},
    {1005, "Webcam HD", 1899.00},
    {1006, "Bluetooth Speaker", 2499.00},
    {1007, "Gaming Headset", 3499.00},
    {1008, "Wireless Earbuds", 2999.00},
    {1009, "Power Bank 10000mAh", 999.00},
    {1010, "Smart Watch", 4999.00},

    {1011, "Phone Charger", 799.00},
    {1012, "HDMI Cable", 499.00},
    {1013, "Laptop Backpack", 1799.00},
    {1014, "External SSD 500GB", 4499.00},
    {1015, "External HDD 1TB", 3999.00},
    {1016, "Wireless Router", 2299.00},
    {1017, "WiFi Range Extender", 1599.00},
    {1018, "Smartphone Tripod", 899.00},
    {1019, "Phone Case", 499.00},
    {1020, "Screen Protector", 299.00},

    {1021, "Gaming Mouse", 1999.00},
    {1022, "Gaming Keyboard", 3999.00},
    {1023, "Gaming Monitor", 12999.00},
    {1024, "USB Hub", 899.00},
    {1025, "Memory Card 128GB", 1199.00},
    {1026, "Memory Card 256GB", 1999.00},
    {1027, "Bluetooth Adapter", 699.00},
    {1028, "Laptop Cooling Pad", 1499.00},
    {1029, "Desk Lamp", 999.00},
    {1030, "LED Strip Lights", 799.00},

    {1031, "Smartphone", 24999.00},
    {1032, "Tablet", 18999.00},
    {1033, "Laptop", 54999.00},
    {1034, "Desktop PC", 69999.00},
    {1035, "Smart TV 43 Inch", 32999.00},
    {1036, "Smart TV 55 Inch", 49999.00},
    {1037, "Bluetooth Headphones", 2499.00},
    {1038, "Noise Cancelling Headphones", 6999.00},
    {1039, "Portable SSD 1TB", 7999.00},
    {1040, "USB Flash Drive 64GB", 699.00},

    {1041, "Fitness Band", 1999.00},
    {1042, "Smart Watch Pro", 8999.00},
    {1043, "Smart Scale", 1999.00},
    {1044, "Electric Toothbrush", 2499.00},
    {1045, "Hair Dryer", 1799.00},
    {1046, "Electric Shaver", 2999.00},
    {1047, "Air Purifier", 8999.00},
    {1048, "Humidifier", 2999.00},
    {1049, "Robot Vacuum", 24999.00},
    {1050, "Coffee Maker", 4999.00},

    {1051, "Water Bottle", 599.00},
    {1052, "Travel Backpack", 2499.00},
    {1053, "Office Chair", 8999.00},
    {1054, "Gaming Chair", 14999.00},
    {1055, "Study Table", 6999.00},
    {1056, "Bookshelf", 4999.00},
    {1057, "Desk Organizer", 799.00},
    {1058, "Notebook Set", 399.00},
    {1059, "Pen Set", 299.00},
    {1060, "Whiteboard", 1499.00},

    {1061, "DSLR Camera", 54999.00},
    {1062, "Mirrorless Camera", 69999.00},
    {1063, "Camera Lens 50mm", 29999.00},
    {1064, "Camera Tripod", 2999.00},
    {1065, "Action Camera", 24999.00},
    {1066, "Camera Bag", 1999.00},
    {1067, "Drone", 44999.00},
    {1068, "Gimbal Stabilizer", 9999.00},
    {1069, "Ring Light", 1999.00},
    {1070, "Studio Microphone", 6999.00},

    {1071, "Bluetooth Keyboard", 1599.00},
    {1072, "Ergonomic Mouse", 1299.00},
    {1073, "Monitor Stand", 1999.00},
    {1074, "27 Inch Monitor", 18999.00},
    {1075, "24 Inch Monitor", 11999.00},
    {1076, "4K Monitor", 29999.00},
    {1077, "Laptop Docking Station", 6999.00},
    {1078, "Thunderbolt Cable", 1999.00},
    {1079, "Ethernet Cable", 399.00},
    {1080, "Network Switch", 2499.00},

    {1081, "Portable Projector", 9999.00},
    {1082, "Projector Screen", 3999.00},
    {1083, "Soundbar", 7999.00},
    {1084, "Home Theater System", 24999.00},
    {1085, "Smart Speaker", 3499.00},
    {1086, "Streaming Stick", 3999.00},
    {1087, "Game Console", 49999.00},
    {1088, "Gaming Controller", 4999.00},
    {1089, "VR Headset", 34999.00},
    {1090, "Gaming Mouse Pad", 999.00},

    {1091, "Printer", 8999.00},
    {1092, "Laser Printer", 14999.00},
    {1093, "Ink Cartridge", 1299.00},
    {1094, "External DVD Drive", 1599.00},
    {1095, "UPS Backup", 4999.00},
    {1096, "Surge Protector", 999.00},
    {1097, "Extension Board", 799.00},
    {1098, "Smart Plug", 999.00},
    {1099, "Smart Bulb", 699.00},
    {1100, "Security Camera", 3999.00}};

void searchById(int pid);
void searchByPrice(int max, int min);
void printProduct(int idx);

void searchById(int pid) {
  int size = sizeof(PRODUCTS) / sizeof(Product);
  int l = 0;
  int r = size - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (PRODUCTS[mid].PId == pid) {
      printProduct(mid);
      return;
    } else if (PRODUCTS[mid].PId > pid) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  printProduct(-1);
  return;
}

void searchByPrice(int max, int min) {
  if (min < 0) {
    std::cout << "\nInvalid, price cannot be lesser than 0.\n";
  } else if (min > max) {
    printProduct(-1);
    std::cout << "\nMinimum price cannot be greater than maximum price.\n";
  }

  int size = sizeof(PRODUCTS) / sizeof(Product);
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (PRODUCTS[i].Price >= min && PRODUCTS[i].Price <= max) {
      count++;
      printProduct(i);
    }
  }
  if (count == 0) {
    std::cout << "\nFound 0 products in price range [" << min << " , " << max
              << "]";
  } else {
    std::cout << "\nFound " << count << " products in price range [" << min
              << " , " << max << "]";
  }
}

void printProduct(int idx) {
  if (idx < 0 || idx > (sizeof(PRODUCTS) / sizeof(Product))) {
    std::cout << "\nNo specified product found. Please try again.";
    return;
  }
  std::cout << "\nProduct ID :" << PRODUCTS[idx].PId
            << ", Name :" << PRODUCTS[idx].PName
            << ", Price :" << PRODUCTS[idx].Price;
  return;
}

int main() {
  int choice;
  do {
    std::cout << "\n\n1. To search by Product ID\n2. To search by Price\n3. To "
                 "Exit\n->";
    std::cin >> choice;

    switch (choice) {
    case 1:
      int pid;
      std::cout << "\nEnter Product ID :";
      std::cin >> pid;
      searchById(pid);
      break;
    case 2:
      int MinPrice;
      std::cout << "\nEnter Minimum Price :";
      std::cin >> MinPrice;

      int MaxPrice;
      std::cout << "\nEnter Maximum Price :";
      std::cin >> MaxPrice;

      searchByPrice(MaxPrice, MinPrice);
      break;
    case 3:
      std::cout << "\nYou choose exit!\n";
      break;
    default:
      std::cout << "\nPlease enter a valid choice between (1 - 3)";
      break;
    }
  } while (choice != 3);

  return 0;
}