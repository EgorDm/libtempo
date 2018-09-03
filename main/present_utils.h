//
// Created by egordm on 3-9-2018.
//

#ifndef PROJECT_PRESENT_UTILS_H
#define PROJECT_PRESENT_UTILS_H

#include <curve_utils.h>
#include <audio_processing.h>

using namespace tempogram;

namespace present_utils {
    std::string split_ext(std::string &path);

    std::string section_to_osu(const curve_utils::Section &section);

    void save_click_track(audio::AudioFile &audio, const std::vector<curve_utils::Section> &sections, int fraction);

    template<typename T>
    inline void write_matrix_data(const std::string &filename, const Mat<T> &data, char type_identifier, const char* extra = nullptr, int extra_size=0)
    {
        std::ofstream file;
        file.open(filename, std::ios_base::binary);
        if (!file.is_open()) {
            std::cerr << "Cant open: " << filename << std::endl;
            exit(1);
        }

        unsigned long long size_data[2] = {data.n_rows, data.n_cols};
        file.write((char *) &size_data, sizeof(size_data));
        file.write(&type_identifier, 1);

        file.write((char *) &extra_size, sizeof(extra_size));

        if (extra != nullptr) {
            file.write(extra, extra_size);
        }

        file.write((char*)data.memptr(), data.size() * sizeof(T));
        file.close();
    }

};


#endif //PROJECT_PRESENT_UTILS_H