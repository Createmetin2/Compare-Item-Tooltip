///Add
#if defined(__COMPARE_TOOLTIP__)
PyObject* itemGetCompareIndex(PyObject* poSelf, PyObject* poArgs)
{
	CItemData* pItemData = CItemManager::Instance().GetSelectedItemDataPointer();
	if (!pItemData)
		return Py_BuildException("no selected item data");

	DWORD idx = 0;
	const BYTE Type = pItemData->GetType();
	const BYTE SubType = pItemData->GetSubType();

	if (Type == CItemData::ITEM_TYPE_ARMOR) {
		switch (SubType) {
		case CItemData::ARMOR_BODY:	idx = c_Equipment_Body; break;
		case CItemData::ARMOR_HEAD:	idx = c_Equipment_Head; break;
		case CItemData::ARMOR_SHIELD:	idx = c_Equipment_Shield; break;
		case CItemData::ARMOR_WRIST:	idx = c_Equipment_Wrist; break;
		case CItemData::ARMOR_FOOTS:	idx = c_Equipment_Shoes; break;
		case CItemData::ARMOR_NECK:	idx = c_Equipment_Neck; break;
		case CItemData::ARMOR_EAR:	idx = c_Equipment_Ear; break;
		}
	}
	else if (Type == CItemData::ITEM_TYPE_WEAPON) {
		idx = c_Equipment_Weapon;
	}
	else if (Type == CItemData::ITEM_TYPE_COSTUME) {
		switch (SubType) {
		case CItemData::COSTUME_BODY:	idx = c_Costume_Slot_Body; break;
		case CItemData::COSTUME_HAIR:	idx = c_Costume_Slot_Hair; break;
#if defined(ENABLE_SASH_SYSTEM)
		case CItemData::COSTUME_SASH:	idx = c_Costume_Slot_Sash; break;
#endif
		}
	}
#if defined(ENABLE_NEW_EQUIPMENT_SYSTEM)
	else if (Type == CItemData::ITEM_TYPE_BELT) {
		idx = c_Equipment_Belt;
	}
#endif

	return Py_BuildValue("i", idx);
}
#endif

//Find
		{ NULL,								NULL,									NULL		 },
		
///Add Below
#if defined(__COMPARE_TOOLTIP__)		
		{ "GetCompareIndex",				itemGetCompareIndex,					METH_VARARGS },
#endif