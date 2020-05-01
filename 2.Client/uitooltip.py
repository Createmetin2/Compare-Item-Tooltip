#Find in : class ToolTip(ui.ThinBoard) / def __init__(self, width = TOOL_TIP_WIDTH, isPickable=False):
		self.ClearToolTip()
		
#Add
		if app.__COMPARE_TOOLTIP__:
			self.CompareTooltip = None
			self.IsCompare = False
			
#Find in : class ToolTip(ui.ThinBoard) / def __del__(self):
		ui.ThinBoard.__del__(self)
		
#Add
		if app.__COMPARE_TOOLTIP__ and self.CompareTooltip:
			del self.CompareTooltip
			
#Find in def HideToolTip(self):
		self.Hide()
		
#Add
		if app.__COMPARE_TOOLTIP__ and self.CompareTooltip:
			self.CompareTooltip.Hide()
			
#Find
		self.SetPosition(x, y)
		
#Add Above
		if app.__COMPARE_TOOLTIP__:
			if self.IsCompare:
				return
			if self.CompareTooltip:
				if x <= self.GetWidth():
					self.CompareTooltip.SetPosition(x+self.GetWidth(), y)
				else:
					self.CompareTooltip.SetPosition(x-self.CompareTooltip.GetWidth(), y)
#Find
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
	
#Change
	# def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY, CompareItem = True):
	
#Find in same function
		self.AddItemData(itemVnum, metinSlot, attrSlot)
		
#Add
		if app.__COMPARE_TOOLTIP__:
			if not CompareItem or slotIndex >= player.EQUIPMENT_SLOT_START:
				return
			if not self.CompareTooltip:
				self.CompareTooltip = ItemToolTip()
				self.CompareTooltip.IsCompare = True
			self.CompareTooltip.Hide()
			idx = item.GetCompareIndex()
			if idx:
				self.CompareTooltip.SetInventoryItem(idx, window_type, False)
				self.CompareTooltip.AutoAppendTextLine("{}Equipped".format("|cffADFF2F"))
				self.CompareTooltip.ResizeToolTip()
