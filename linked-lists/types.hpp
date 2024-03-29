#include <unordered_set>

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

struct unode;
bool ancestor_of(unode* a, unode* b);
bool connected(unode* a, unode* b);

struct unode // graph node with unweighted edges and non-duplicate links
{
	int data = 0;
	std::unordered_set<unode*> children;
	std::unordered_set<unode*> parents;

	bool set(int arg) { data = arg; return (data == arg); }
	bool clear()      { data = 0;   return (data == 0);   }

	bool add_child(unode* arg) 
	{ 
		children.insert(arg);
		arg->parents.insert(this);

		return (children.contains(arg)); 
	}
	bool remove_child(unode* arg)
	{ 
		children.erase(children.find(arg));
		arg->parents.erase(arg->parents.find(this));
		return !(children.contains(arg));
	}

	bool remove_parent(unode* arg)
	{
		arg->remove_child(this);
		parents.erase(parents.find(arg));
		return !(parents.contains(arg));
	}

	bool remove_all_children()
	{
		for(auto& i : children)
		{
			remove_child(i);	
		}
		children.clear();
		return (children.size() == 0);
	}

	bool remove_all_parents()
	{
		for(auto& i : parents)
		{
			remove_parent(i);
		}
		parents.clear();
		return (parents.size() == 0);
	}

	bool operator==(unode& rhs)
	{
		return (*this == rhs);
	}
	bool operator!=(unode &rhs)
	{
		return !(*this == rhs);
	}

	bool loops()
	{
		return ancestor_of(this, this);
	}

};

bool ancestor_of(unode* a, unode* b)
{
	if(a->children.contains(b)) { return true; } else
	{
		for(auto i: a->children)
		{
			return ancestor_of(i, b);
		}
	}

	return false;
}

bool connected(unode* a, unode* b)
{
	return(ancestor_of(a, b) or ancestor_of(b, a));
}