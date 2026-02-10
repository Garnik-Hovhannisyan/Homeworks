#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <utility>

namespace my
{
	template <typename T>
	class shared_ptr
	{
	private:
		T* m_ptr;
		long* m_ref_count;

		void reset()
		{
			if (m_ref_count)
			{
				--(*m_ref_count);

				if (*m_ref_count == 0)
				{
					delete m_ptr;
					delete m_ref_count;
				}
			}

			m_ptr = nullptr;
			m_ref_count = nullptr;
		}

	public:
		shared_ptr() noexcept : m_ptr(nullptr), m_ref_count(nullptr) {}
		explicit shared_ptr(T* p) noexcept : m_ptr(p), m_ref_count(new long(1)) {}

		shared_ptr(const shared_ptr& other) noexcept: m_ptr(other.m_ptr), m_ref_count(other.m_ref_count)
		{
			if (m_ref_count) { ++(*m_ref_count); }
		}

		shared_ptr& operator=(const shared_ptr& other) noexcept
		{
			if (this != &other)
			{
				reset();

				m_ptr = other.m_ptr;
				m_ref_count = other.m_ref_count;

				if (m_ref_count) { ++(*m_ref_count); }
			}

			return *this;
		}

		shared_ptr(shared_ptr&& other) noexcept : m_ptr(other.m_ptr), m_ref_count(other.m_ref_count)
		{
			other.m_ptr = nullptr;
			other.m_ref_count = nullptr;
		}

		shared_ptr& operator=(shared_ptr&& other) noexcept
		{
			if (this != &other)
			{
				reset();

				m_ptr = other.m_ptr;
				m_ref_count = other.m_ref_count;

				other.m_ptr = nullptr;
				other.m_ref_count = nullptr;
			}

			return *this;
		}

		~shared_ptr() { reset(); }

	public:
		void swap(shared_ptr& other) noexcept
		{
			std::swap(m_ptr, other.m_ptr);
			std::swap(m_ref_count, other.m_ref_count);
		}

		T* get() const noexcept { return m_ptr; }

		T& operator*() const noexcept { return *m_ptr; }
		T operator*() noexcept { return *m_ptr; }

		T* operator->() const noexcept { return m_ptr; }
		T* operator->() noexcept { return m_ptr; }

		long use_count() const noexcept
		{
			if (m_ref_count != nullptr) { return *m_ref_count; }
			else { return 0; }
		}

		bool unique() const noexcept
		{
			if (m_ref_count != nullptr && *m_ref_count == 1) { return true; }
			else { return false; }
		}

		explicit operator bool() const noexcept { return m_ptr != nullptr; }
	};
}


#endif // SHARED_PTR_H