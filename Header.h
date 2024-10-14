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
			cout << "ʳ������ �������� �� ���� ���� ����� 1\n";
		}
		else {
			while (n > 0) {
				Link* temp = new Link;
				cout << "������ ��������: ";
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
			cout << "������ �������!";
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
			cout << "������ �������!";
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
			cout << "������ �������!";
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
	//��������
	void clear() {
		while (!is_empty()) {
			pop_front();
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
		// ����� ��������
		while (temp != nullptr && temp->val != x) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "������� �� ��������!\n";
			return;
		}
		// ��������� ������� ��������
		if (temp == first) {
			pop_front();
		}
		else if (temp == last) {
			pop_back();
		}
		// ��������� �������� � ������� ��� ���� ������
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		cout << "������� ��������!\n";
	}

	void swap_el(float x, float y) {
		if (x == y) {
			cout << "����� �������� �������, ���� ����� ����� ������\n";
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