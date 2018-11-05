auto start = std::chrono::steady_clock::now();
auto finish = std::chrono::steady_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

tfm::printfln("one frame consumed %s ms", elapsed);