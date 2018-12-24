-- andand.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(xs[i] == 1 && xs[i+1] == 1 && xs[i+2] == 1 && xs[i+3] == 1)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- andand_double.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = double;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;int&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = static_cast&lt;TheType&gt;(distribution(rng));
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(xs[i] == 1 && xs[i+1] == 1 && xs[i+2] == 1 && xs[i+3] == 1)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- andand_float.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = float;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;int&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = static_cast&lt;TheType&gt;(distribution(rng));
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(xs[i] == 1 && xs[i+1] == 1 && xs[i+2] == 1 && xs[i+3] == 1)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- and.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(xs[i] == 1 & xs[i+1] == 1 & xs[i+2] == 1 & xs[i+3] == 1)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- compare_zero.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_0_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(xs[i] == 0 && xs[i+1] == 0 && xs[i+2] == 0 && xs[i+3] == 0)
      four_0_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  0000s: " &lt;&lt; four_0_in_a_row &lt;&lt; "\n";
}


-- minus_abs_plus.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;


int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(std::abs(xs[i] - 1) 
     + std::abs(xs[i+1] - 1) 
     + std::abs(xs[i+2] - 1) 
     + std::abs(xs[i+3] - 1) == 0)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- minus_mul_plus.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

inline int sq(int x) {
  return x*x;
}

int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(sq(xs[i] - 1)
     + sq(xs[i+1] - 1)
     + sq(xs[i+2] - 1) 
     + sq(xs[i+3] - 1) == 0)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- minus_mul_plus_double.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

double sq(double x) {
  return x*x;
}

int main() {
  using TheType = double;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;int&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = static_cast&lt;TheType&gt;(distribution(rng));
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if(sq(xs[i] - 1) 
     + sq(xs[i+1] - 1)
     + sq(xs[i+2] - 1)
     + sq(xs[i+3] - 1) == 0)
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


-- mul.cpp

#include &lt;chrono&gt;
#include &lt;iostream&gt;
#include &lt;random&gt;
#include &lt;array&gt;

int main() {
  using TheType = int;
  constexpr auto TheSize = 16 * 10000000;
  std::mt19937 rng(0);
  std::uniform_int_distribution&lt;TheType&gt; distribution(0, 1);
  std::vector&lt;TheType&gt; xs(TheSize);
  for (TheType &digit : xs) {
    digit = distribution(rng);
  }
   
  volatile auto four_1_in_a_row = 0u;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i &lt; TheSize - 3; i += 1)
    if((xs[i] == 1) * (xs[i+1] == 1) * (xs[i+2] == 1) * (xs[i+3] == 1))
      four_1_in_a_row++; 
  auto end = std::chrono::system_clock::now();
  
  std::cout &lt;&lt; "time: " &lt;&lt; (end-start).count() * 1e-9  
    &lt;&lt; "  1111s: " &lt;&lt; four_1_in_a_row &lt;&lt; "\n";
}


