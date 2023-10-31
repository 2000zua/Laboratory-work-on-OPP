class IXmlIO {
public:
    virtual void fromXml(const xml_node& node) = 0;
    virtual void toXml(xml_node& node) const = 0;
    virtual ~IXmlIO() {}
};