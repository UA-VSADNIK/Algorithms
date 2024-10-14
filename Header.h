using namespace std;
struct Link {
	float val;
	Link* next;
};

struct List {
	Link* first;
	Link* last;
	List() :first(nullptr), last(nullptr) {}
	
	bool is_empty() { return first == nullptr; }
	
	//��������
	void clear() {
		if (this->is_empty()) {
			cout << "������ �������!\n";
		}
		else {
			while (!is_empty()) {
				Link* temp = first;
				first = first->next;
				delete temp;
			}
			last = nullptr;
		}
	}

	void make_List(int n) {	
		if (n < 1) {
			cout << "ʳ������ �������� �� ���� ���� ����� 1\n";
		}
		else {
			clear();
			while (n > 0) {
				Link* temp = new Link;
				cout << "������ ��������: ";
				cin >> temp->val;
				temp->next = nullptr;
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
		if (this->is_empty()) {
			temp->next = nullptr;
			last = first = temp;
		}
		else first = temp;
	}
	
	void pop_back() {
		if (is_empty()) {
			cout << "������ �������!\n";
		}
		else {
			Link* temp = first;
			while (temp->next != last) {
				temp = temp->next;
			}
			delete last;
			last = temp;
			last->next = nullptr;
		}
	}
	
	void pop_front() {
		if (is_empty()) {
			cout << "������ �������!\n";
		}
		else {
			Link* temp = first;
			first = first->next;
			delete temp;
		}
	}
	void display() {
		if (is_empty()) {
			cout << "������ �������!\n";
		}
		else {
			Link* temp = first;
			cout << "������� ������: ";
			while (temp != nullptr) {
				cout << temp->val << "   ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	//ʳ������ ��������
	void num_of_el() {
		int count = 0;
		Link* temp = first;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		cout << "ʳ������ ��������: " << count << endl;
	}
	//��������� ������ ��������
	void delete_one_el(float x) {
		if (is_empty()) {
			cout << "������ �������!\n";
			return;
		}
		Link* temp = first;
		Link* prev = nullptr;
		// ����� ��������
		while (temp != nullptr && temp->val != x) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "������� �� ��������!\n";
			return;
		}
		// ��������� ������� ��������
		if (temp == first) {
			first = first->next;
			if (first == nullptr) {
				last = nullptr;
			}
			delete temp;
		}
		// ��������� �������� � ������� ��� ���� ������
		else {
			prev->next = temp->next;
			if (temp == last) { 
				last = prev;
			}
			delete temp;
		}
		cout << "������� ��������!\n";
	}

	void swap_el(float x, float y) {
		if (x == y) {
			cout << "����� �������� �������, ���� ����� ����� ������.\n";
			return;
		}
		Link* X = first;
		Link* Y = first;
		//��������� X
		while (X != nullptr && X->val != x) {
			X = X->next;
		}
		//��������� Y
		while (Y != nullptr && Y->val != y) {
			Y = Y->next;
		}
		if (X == nullptr || Y == nullptr) {
			cout << "�������� �� �������\n";
			return;
		}
		swap(X->val, Y->val);
	}
	//����� � ����
	void save_to_file(const string& filename) {
		if (is_empty()) {
			cout << "������ �������, ���� �� ����������\n";
			return;
		}
		ofstream fout(filename);
		if (!fout.is_open()) {
			cout << "�� ������� ������� ���� ��� ������.\n";
			return;
		}
		Link* temp = first;
		while (temp != nullptr) {
			fout << temp->val << endl;
			temp = temp->next;
		}

		fout.close();
		cout << "��� ������ �������� � ���� " << filename << endl;
	}
	//����� � �����
	void load_from_file(const string& filename) {
		ifstream fin(filename);
		if (!fin.is_open()) {
			cout << "�� ������� ������� ���� ��� �������.\n";
			return;
		}
		clear();
		float val;
		while (fin >> val) {
			push_back(val);
		}
		fin.close();
		cout << "��� ������ ����������� � ����� " << filename << endl;
	}
};