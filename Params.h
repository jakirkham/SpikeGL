#ifndef Params_H
#define Params_H
#include <QMap>
#include <QVariant>
#include <QString>

/**
   \brief Encapsulates a dictionary of name/value pairs that can be saved to disk.

   An association of name/value pairs.  The names are strings and the values
   are a QVariant (float, int, string, etc -- anything QVariant supports).

   Use the toString() method to generate a config-file style string
   (suitable to pass to matlab clients or to save as a config file).

   The fromString() function parses parameters.

   Format for the string that the toString() and fromString() functions use is

   \code
   name1 = value1
   name2 = value2
   ...etc...
   \endcode
   (this is much like the configuration file format for StimulateOpenGL)  
*/   
class Params : public QMap<QString, QVariant>
{
public:
    Params() {}
    Params(const QString &str) { fromString(str); }
    /// Parses an ini-stile string to set the params
    void fromString(const QString &);
    /** Creates an ini-style multi-line string of the params.
        Format is as follows:
        \code 
           name1=value1
           name2=value2
           ...etc...
        \endcode
        
        This is basically the same format at the original StimulateOpenGL 
        configuration file format.
    */
    QString toString() const;
    /// Reads the entire contents of file into memory as a QString then calls fromString() on this string.
    bool fromFile(const QString & fileName);
    /// Writes the entire contents of the dictionary to a big string, which then gets saved to fileName. Optionally filename is appended-to and not truncated!
    bool toFile(const QString & fileName, bool appendDontTruncate = false) const;
	
};

#endif
