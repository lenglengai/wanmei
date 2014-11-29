using System;
using System.Collections.Generic;

namespace common.core
{
    public class SqlCommand : ISqlCommand
    {
        public void _serialize(ref bool nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"TINYINT(1)", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            }  else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            }  else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref sbyte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10)", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<sbyte> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref byte nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10) UNSIGNED", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<byte> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref byte[] nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._createBlob(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._selectBlob(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._insertUpdateEBlob(nValue, nName);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._insertUpdateExBlob(nName);
            }
        }

        public void _serialize(ref short nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10)", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<short> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref ushort nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10) UNSIGNED", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<ushort> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref int nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10)", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<int> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref uint nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"INT(10) UNSIGNED", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<uint> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref long nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"BIGINT", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<long> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref ulong nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"BIGINT UNSIGNED", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<ulong> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref string nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"VARCHAR(255)", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<string> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref float nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"FLOAT", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<float> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize(ref double nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (SqlDeal_.mCreate_ == mSqlDeal) {
                this._runCreate(@"DOUBLE", nName, nSqlFieldId);
            } else if ((SqlDeal_.mPrimary_ == mSqlDeal)
                && ((nSqlFieldId & SqlFieldId_.mPrimary_) > 0)) {
                this._runPrimary(nName);
            } else if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nName);
            } else if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nName);
            } else if (SqlDeal_.mInsertUpdateE_ == mSqlDeal) {
                this._runInsertUpdateE(nName, nValue);
            } else if (SqlDeal_.mInsertUpdateEx_ == mSqlDeal) {
                this._runInsertUpdateEx(nName);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else if (SqlDeal_.mUpdateSelect_ == mSqlDeal) {
                this._updateSelect(nName);
            } else if (SqlDeal_.mUpdateWhen_ == mSqlDeal) {
                this._updateWhen(nValue);
            } else if (SqlDeal_.mUpdateThen_ == mSqlDeal) {
                this._updateThen(nValue, nName);
            } else {
            }
        }

        public void _serialize(ref List<double> nValue, string nName) {
            if (SqlDeal_.mWhere_ == mSqlDeal) {
                this._runWhere(nValue, nName);
            }
        }

        public void _serialize<__t>(ref __t nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
        }

        public void _serialize<__t>(ref List<__t> nValue, string nName)
            where __t : ISqlStream {
            if (SqlDeal_.mSelect_ == mSqlDeal) {
                this._runSelect(nValue);
            } else if (SqlDeal_.mInsert_ == mSqlDeal) {
                this._runInsert(nValue);
            } else if (SqlDeal_.mInsertUpdate_ == mSqlDeal) {
                this._runInsertUpdate(nValue);
            } else if (SqlDeal_.mUpdate_ == mSqlDeal) {
                this._runUpdate(nValue, nName);
            } else {
            }
        }

        public void _addHeadstream(ISqlHeadstream nSqlStream) {
            SqlType_ sqlType_ = nSqlStream._sqlType();
            if (SqlType_.mCreate_ == sqlType_) {
                this._runCreate(nSqlStream);
            } else if (SqlType_.mSelect_ == sqlType_) {
                this._runSelect(nSqlStream);
            } else if (SqlType_.mInsert_ == sqlType_) {
                this._runInsert(nSqlStream);
            } else if (SqlType_.mInsertUpdate_ == sqlType_) {
                this._runInsertUpdate(nSqlStream);
            } else if (SqlType_.mInsertUpdateEx_ == sqlType_) {
                this._runInsertUpdateEx(nSqlStream);
            } else if (SqlType_.mUpdate_ == sqlType_) {
                this._runUpdate(nSqlStream);
            } else if (SqlType_.mDelete_ == sqlType_) {
                this._runDelete(nSqlStream);
            } else {
            }
        }

        public void _runCreate(ISqlHeadstream nSqlHeadstream) {
            mValue += @"CREATE TABLE ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @"(";
            mBeg = true;
            mSqlDeal = SqlDeal_.mCreate_;
            nSqlHeadstream._runSelect(this);
            mBeg = true;
            mEnd = false;
            mSqlDeal = SqlDeal_.mPrimary_;
            nSqlHeadstream._runSelect(this);
            if (mEnd) {
                mValue += @")";
            }
            mValue += @")ENGINE=MYISAM DEFAULT CHARSET=utf8;";
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runCreate(string nValue, string nName,
            SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += " ";
            mValue += nValue;
            if ((nSqlFieldId & SqlFieldId_.mZeroFill_) > 0) {
                mValue += " ZEROFILL";
            }
            if ((nSqlFieldId & SqlFieldId_.mBinary_) > 0) {
                mValue += " BINARY";
            }
            if ((nSqlFieldId & SqlFieldId_.mNotNull_) > 0) {
                mValue += " NOT NULL";
            }
            if ((nSqlFieldId & SqlFieldId_.mAutoIncremet_) > 0) {
                mValue += " AUTO_INCREMENT";
            }
            if (mBeg) {
                mBeg = false;
            }
        }

        void _createBlob(string nName) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += string.Format(@"{0}_i", nName);
            mValue += mFieldCharacter;
            mValue += " INT(10) ZEROFILL NOT NULL,";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += " BLOB NULL";
            if (mBeg) {
                mBeg = false;
            }
        }

        void _runPrimary(string nName) {
            if (false == mBeg) {
                mValue += @",";
            } else {
                mValue += @", PRIMARY KEY (";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mEnd = true;
            if (mBeg) {
                mBeg = false;
            }
        }

        public void _runSelect(ISqlHeadstream nSqlHeadstream) {
            mValue += @"SELECT ";
            mBeg = true;
            mSqlDeal = SqlDeal_.mSelect_;
            nSqlHeadstream._runSelect(this);
            mValue += @" FROM ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" ";
            mSqlDeal = SqlDeal_.mWhere_;
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runSelect(string nName) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }

        void _selectBlob(string nName) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += string.Format(@"{0}_i", nName);
            mValue += mFieldCharacter;
            mValue += ",";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }

        void _runSelect<__t>(List<__t> nValue)
            where __t : ISqlStream {
            if (nValue.Count > 0) {
                nValue[0]._runSelect(this);
            } else {
                __t t_ = Activator.CreateInstance<__t>();
                t_._runSelect(this);
            }
        }

        void _runWhere<__t>(__t nValue, string nName) {
            mValue += nName;
            mValue += mValueCharacter;
            mValue += Convert.ToString(nValue);
            mValue += mValueCharacter;
            mValue += " ";
        }

        public void _runInsert(ISqlHeadstream nSqlHeadstream) {
            mValue += @"INSERT INTO ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" (";
            mBeg = true;
            mSqlDeal = SqlDeal_.mSelect_;
            nSqlHeadstream._runSelect(this);
            mValue += @") VALUES (";
            mBeg = true;
            mSqlDeal = SqlDeal_.mInsert_;
            nSqlHeadstream._runSelect(this);
            mValue += @") ";
            mSqlDeal = SqlDeal_.mWhere_;
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runInsert<__t>(__t nValue) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mValueCharacter;
            mValue += Convert.ToString(nValue);
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }

        void _runInsert<__t>(List<__t> nValue)
            where __t : ISqlStream {
            bool temp_ = false;
            foreach (__t i in nValue) {
                if (temp_) {
                    mValue += "),(";
                    mBeg = true;
                }
                i._runSelect(this);
                temp_ = true;
            }
        }

        public void _runInsertUpdate(ISqlHeadstream nSqlHeadstream) {
            mValue += @"INSERT INTO ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" (";
            mBeg = true;
            mSqlDeal = SqlDeal_.mSelect_;
            nSqlHeadstream._runSelect(this);
            mValue += @") VALUES (";
            mBeg = true;
            mSqlDeal = SqlDeal_.mInsert_;
            nSqlHeadstream._runSelect(this);
            mValue += @") ";
            mSqlDeal = SqlDeal_.mInsertUpdate_;
            nSqlHeadstream._runSelect(this);
            mSqlDeal = SqlDeal_.mWhere_;
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runInsertUpdate(string nName) {
            if (false == mBeg) {
                mValue += @",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @"=VALUES(";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @")";
            if (mBeg) {
                mBeg = false;
            }
        }

        void _runInsertUpdate<__t>(List<__t> nValue)
            where __t : ISqlStream {
            mValue += "ON DUPLICATE KEY UPDATE ";
            mBeg = true;
            foreach (__t i in nValue) {
                i._runSelect(this);
                break;
            }
        }

        public void _runInsertUpdateEx(ISqlHeadstream nSqlHeadstream) {
            mValue += @"INSERT INTO ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" VALUES (";
            mBeg = true;
            mSqlDeal = SqlDeal_.mInsertUpdateE_;
            nSqlHeadstream._runSelect(this);
            mValue += @") ON DUPLICATE KEY UPDATE ";
            mBeg = true;
            mSqlDeal = SqlDeal_.mInsertUpdateEx_;
            nSqlHeadstream._runSelect(this);
            mSqlDeal = SqlDeal_.mWhere_;
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runInsertUpdateE<__t>(string nName, __t nValue) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mUpdateCharacter;
            mValue += nName;
            if (mBeg) {
                mBeg = false;
            }
            SqlParameter sqlParameter_ =
                new SqlParameter(nName, nValue);
            mFields.Add(sqlParameter_);
        }

        void _insertUpdateEBlob(byte[] nValue, string nName) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mUpdateCharacter;
            string name_ = string.Format(@"{0}_i", nName);
            mValue += name_;
            mValue += ",";
            mValue += mUpdateCharacter;
            mValue += nName;
            if (mBeg) {
                mBeg = false;
            }
            SqlParameter sqlParameter_ =
                new SqlParameter(name_, nValue.GetLength(0));
            mFields.Add(sqlParameter_);
            sqlParameter_ = new SqlParameter(nName, nValue);
            mFields.Add(sqlParameter_);
        }

        void _runInsertUpdateEx(string nName) {
            if (false == mBeg) {
                mValue += @",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @"=VALUES(";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @")";
            if (mBeg) {
                mBeg = false;
            }
        }

        void _insertUpdateExBlob(string nName) {
            if (false == mBeg) {
                mValue += @",";
            }
            mValue += mFieldCharacter;
            mValue += string.Format(@"{0}_i", nName);
            mValue += mFieldCharacter;
            mValue += @"=VALUES(";
            mValue += mFieldCharacter;
            mValue += string.Format(@"{0}_i", nName);
            mValue += mFieldCharacter;
            mValue += @"),";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @"=VALUES(";
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += @")";
            if (mBeg) {
                mBeg = false;
            }
        }

        public void _runUpdate(ISqlHeadstream nSqlHeadstream) {
            mValue += @"UPDATE ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" SET ";
            mBeg = true;
            mSqlDeal = SqlDeal_.mUpdate_;
            nSqlHeadstream._runSelect(this);
            mSqlDeal = SqlDeal_.mWhere_;
            mValue += @" ";
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runUpdate<__t>(__t nValue, string nName) {
            if (false == mBeg) {
                mValue += ",";
            }
            mValue += mFieldCharacter;
            mValue += nName;
            mValue += mFieldCharacter;
            mValue += "=";
            mValue += mValueCharacter;
            mValue += Convert.ToString(nValue);
            mValue += mValueCharacter;
            if (mBeg) {
                mBeg = false;
            }
        }

        void _runUpdate<__t>(List<__t> nValue, string nName)
            where __t : ISqlStream {
            mUpdate.Clear();
            mSqlDeal = SqlDeal_.mUpdateSelect_;
            foreach (__t i in nValue) {
                i._runSelect(this);
                break;
            }
            bool temp_ = true;
            foreach (string i in mUpdate) {
                mName = i;
                if (false == temp_) {
                    mValue += ",";
                }
                mValue += mFieldCharacter;
                mValue += mName;
                mValue += mFieldCharacter;
                mValue += "= CASE ";
                mSqlDeal = SqlDeal_.mSelect_;
                mBeg = true;
                foreach (__t j in nValue) {
                    j._runWhen(this);
                    break;
                }
                foreach (__t j in nValue) {
                    mSqlDeal = SqlDeal_.mUpdateWhen_;
                    mValue += " WHEN ";
                    j._runWhen(this);
                    mSqlDeal = SqlDeal_.mUpdateThen_;
                    mValue += "THEN ";
                    j._runSelect(this);
                }
                mValue += " END";
                if (temp_) {
                    temp_ = false;
                }
            }
            mValue += " WHERE ";
            mSqlDeal = SqlDeal_.mSelect_;
            mBeg = true;
            foreach (__t i in nValue) {
                i._runWhen(this);
                break;
            }
            mSqlDeal = SqlDeal_.mInsert_;
            mBeg = true;
            mValue += " IN (";
            foreach (__t i in nValue) {
                i._runWhen(this);
            }
            mValue += ")";
        }

        void _updateSelect(string nName) {
            mUpdate.Add(nName);
        }

        void _updateWhen<__t>(__t nValue) {
            mValue += mValueCharacter;
            mValue += Convert.ToString(nValue);
            mValue += mValueCharacter;
            mValue += " ";
        }

        void _updateThen<__t>(__t nValue, string nName) {
            if (mName == nName) {
                mValue += mValueCharacter;
                mValue += Convert.ToString(nValue);
                mValue += mValueCharacter;
            }
        }

        public void _runDelete(ISqlHeadstream nSqlHeadstream) {
            mValue += @"DELETE FROM ";
            mValue += mFieldCharacter;
            mValue += nSqlHeadstream._tableName();
            mValue += mFieldCharacter;
            mValue += @" ";
            mSqlDeal = SqlDeal_.mWhere_;
            nSqlHeadstream._runWhere(this);
            mSqlDeal = SqlDeal_.mNone_;
        }

        void _runWhere<__t>(List<__t> nValue, string nName) {
            bool beg_ = true;
            mValue += nName;
            mValue += "(";
            foreach (__t i in nValue) {
                if (false == beg_) {
                    mValue += ",";
                }
                mValue += mValueCharacter;
                mValue += Convert.ToString(i);
                mValue += mValueCharacter;
                beg_ = false;
            }
            mValue += ") ";
        }

        public IList<SqlParameter> _getFields() {
            return mFields;
        }

        public string _sqlCommand() {
            return mValue;
        }

        public SqlCommand() {
            mFields = new List<SqlParameter>();
            mUpdate = new List<string>();
            mSqlDeal = SqlDeal_.mNone_;
            mValue = null;
            mName = null;
            mBeg = false;
            mEnd = false;
        }

        List<SqlParameter> mFields;
        List<string> mUpdate;
        SqlDeal_ mSqlDeal;
        string mValue;
        string mName;
        bool mBeg;
        bool mEnd;

        static readonly string mValueCharacter = @"'";
        static readonly string mFieldCharacter = @"`";
        static readonly string mUpdateCharacter = @"@";
    }
}
