namespace lib {
class NoCopy
{
public:
	NoCopy() {}
	//NoCopy(const NoCopy &) = delete;
	NoCopy &operator = (const NoCopy &) = delete;
};
}//end of lib