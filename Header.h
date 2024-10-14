using namespace std;
struct Link {
	float val;
	Link* next;
	Link* prev;
};

struct List {
	Link* first;
	Link* last;
	List() :first(nullptr), last(nullptr) {}

	bool is_empty() { return first == nullptr; }

	void make_List(int n) {
		if (n < 1) {
			cout << "Кількість елементів не може бути менше 1\n";
		}
		else {
			while (n > 0) {
				Link* temp = new Link;
				cout << "Введіть значення: ";
				cin >> temp->val;
				temp->next = nullptr;
				temp->prev = last;
				if (this->is_empty()) {
					first = last = temp;
				}
				else
				{
					last->next = temp;
					last = temp;
					
				}
				n--;
			}
		}
	}

	void push_back(float x) {
		Link* temp = new Link;
		temp->val = x;
		temp->next = nullptr;
		temp->prev = last;
		if (this->is_empty())
			first = last = temp;
		else
		{
			last->next = temp;
			last = temp;
		}
	}

	void push_front(float x) {
		Link* temp = new Link;
		temp->val = x;
		temp->next = first;
		temp->prev = nullptr;
		if (this->is_empty()) {
			temp->next = nullptr;
			last = first = temp;
		}
		else {
			first->prev = temp;
			first = temp;
		}
	}

	void pop_back() {
		if (is_empty()) {
			cout << "Список порожній!";
			return;
		}
		Link* temp = last;
		last = last->prev;
		if (last != nullptr) {
			last->next = nullptr;
		}
		else {
			first = nullptr;
		}
		delete temp;
	}

	void pop_front() {
		if (is_empty()) {
			cout << "Список порожній!";
			return;
		}
		Link* temp = first;
		first = first->next;
		if (first != nullptr) {
			first->prev = nullptr;
		}
		else {
			last = nullptr;
		}
		delete temp;
	}

	void display() {
		if (is_empty()) {
			cout << "Список порожній!";
		}
		else {
			Link* temp = first;
			cout << "Елемети списку: ";
			while (temp != nullptr) {
				cout << temp->val << "   ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	//Очищення
	void clear() {
		while (!is_empty()) {
			pop_front();
		}
	}
	//Кількість елементів
	void num_of_el() {
		int count = 0;
		Link* temp = first;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		cout << "Кількість елементів: " << count << endl;
	}
	//Видалення одного елементу
	void delete_one_el(float x) {
		if (is_empty()) {
			cout << "Список порожній!\n";
			return;
		}
		Link* temp = first;
		// Пошук елемента
		while (temp != nullptr && temp->val != x) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "Елемент не знайдено!\n";
			return;
		}
		// Видалення першого елемента
		if (temp == first) {
			pop_front();
		}
		else if (temp == last) {
			pop_back();
		}
		// Видалення елемента в середині або кінці списку
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		cout << "Елемент видалено!\n";
	}

	void swap_el(float x, float y) {
		if (x == y) {
			cout << "Обрані елементи однакові, немає сенсу міняти місцями\n";
			return;
		}
		Link* X = first;
		Link* Y = first;
		//Знаходимо X
		while (X != nullptr && X->val != x) {
			X = X->next;
		}
		//Знаходимо Y
		while (Y != nullptr && Y->val != y) {
			Y = Y->next;
		}
		if (X == nullptr || Y == nullptr) {
			cout << "Елементи не знайдені\n";
			return;
		}
		swap(X->val, Y->val);
	}
	//Запис у файл
	void save_to_file(const string& filename) {
		if (is_empty()) {
			cout << "Список порожній, немає що записувати\n";
			return;
		}
		ofstream fout(filename);
		if (!fout.is_open()) {
			cout << "Не вдалося відкрити файл для запису.\n";
			return;
		}
		Link* temp = first;
		while (temp != nullptr) {
			fout << temp->val << endl;
			temp = temp->next;
		}
		fout.close();
		cout << "Дані успішно записано у файл " << filename << endl;
	}
	//Запис з файлу
	void load_from_file(const string& filename) {
		ifstream fin(filename);
		if (!fin.is_open()) {
			cout << "Не вдалося відкрити файл для читання.\n";
			return;
		}
		clear();
		float val;
		while (fin >> val) {
			push_back(val);
		}
		fin.close();
		cout << "Дані успішно завантажено з файлу " << filename << endl;
	}
};