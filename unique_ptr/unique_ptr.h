#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace my
{
	template <typename T>
	class unique_ptr
	{
	private:
		T* m_ptr;

	public:
		unique_ptr() noexcept : m_ptr(nullptr) {}
		explicit unique_ptr(T* p) noexcept : m_ptr(p) {}
		
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		unique_ptr(unique_ptr&& other) noexcept : m_ptr(other.m_ptr) { other.m_ptr = nullptr; }

		unique_ptr& operator=(unique_ptr&& other) noexcept
		{
			if (this != &other)
			{
				delete m_ptr;
				m_ptr = other.m_ptr;
				other.m_ptr = nullptr;
			}

			return *this;
		}

		~unique_ptr() noexcept { delete m_ptr; }

	public:
		T* release() noexcept
		{
			T* temp = m_ptr;
			m_ptr = nullptr;
			return temp;
		}

		void reset(T* p) noexcept
		{
			if (p == m_ptr) { return; }
			delete m_ptr;
			m_ptr = p;
		}

		void swap(unique_ptr& other) noexcept
		{
			std::swap(m_ptr, other.m_ptr);
		}

		T* get() const noexcept { return m_ptr; }

		explicit operator bool() const noexcept { return m_ptr != nullptr; }

		T& operator*() const noexcept { return *m_ptr; }

		T* operator->() noexcept { return m_ptr; }
		T* operator->() const noexcept { return m_ptr; }		
	};
}

#endif // UNIQUE_PTR_H