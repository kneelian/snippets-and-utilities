struct s_list	// singly linked
{
	int data = 0;
	s_list* next = nullptr;

	bool add_child(s_list* arg)
	{
		next = arg;
		return (next != nullptr);
	}

	bool remove_child()
	{
		next = nullptr;
		return (next == nullptr);
	}

	bool set(int arg)
	{
		data = arg;
		return (data == arg);
	}

	bool clear()
	{
		data = 0;
		return (data == 0);
	}
		
};

struct d_list // doubly linked
{
	int data = 0;
	d_list* next = nullptr;
	d_list* prev = nullptr;

	bool add_child(d_list* arg)
	{
		next = arg;
		return (next != nullptr);
	}

	bool remove_child()
	{
		next = nullptr;
		return (next == nullptr);
	}

	bool add_parent(d_list* arg)
	{
		prev = arg;
		return (prev != nullptr);
	}

	bool remove_parent()
	{
		prev = nullptr;
		return (prev == nullptr);
	}

	bool set(int arg)
	{
		data = arg;
		return (data == arg);
	}

	bool clear()
	{
		data = 0;
		return (data == 0);
	}
};