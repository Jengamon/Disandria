#ifndef __IMAGE_H_
#define __IMAGE_H_

#include "../helplib/stringh.h"

namespace pugitmx
{
	class Image
	{
		public:
			Image() {};
			Image(std::string src, unsigned int wd, unsigned int ht, std::string trns) : source(src), width(wd), height(ht), trans(trns) {};
			std::string getSourceString() const;
			unsigned int getWidth() const;
			unsigned int getHeight() const;
			std::string getTrans() const;
		private:
			std::string source;
			unsigned int width;
			unsigned int height;
			std::string trans;
	};
};

#endif // __IMAGE_H_
